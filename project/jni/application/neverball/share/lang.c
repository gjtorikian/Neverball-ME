/*
 * Copyright (C) 2006 Jean Privat
 * Part of the Neverball Project http://icculus.org/neverball/
 *
 * NEVERBALL is  free software; you can redistribute  it and/or modify
 * it under the  terms of the GNU General  Public License as published
 * by the Free  Software Foundation; either version 2  of the License,
 * or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT  ANY  WARRANTY;  without   even  the  implied  warranty  of
 * MERCHANTABILITY or  FITNESS FOR A PARTICULAR PURPOSE.   See the GNU
 * General Public License for more details.
 */

#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include "lang.h"
#include "common.h"
#include "base_config.h"
#include "fs.h"

#ifdef ANDROID
#include <android_support.h>
#endif

/*---------------------------------------------------------------------------*/

#define DEFAULT_CODESET "UTF-8"

/*---------------------------------------------------------------------------*/

char *trim_quotes_and_whitespace(char *str)
{
  char *end;

  // Trim leading quote
  str++;

  // Trim trailing \n
  end = str + strlen(str) - 1;
  end--;

  // Trim trailing quote
  end--;

  // Write new null terminator
  *(end+1) = 0;

  return str;
}

void lang_init(const char *domain)
{
#if ENABLE_NLS && !ANDROID
    char *dir = strdup(getenv("NEVERBALL_LOCALE"));

    if (!dir)
    {
        if (path_is_abs(CONFIG_LOCALE))
            dir = strdup(CONFIG_LOCALE);
        else
            dir = concat_string(fs_base_dir(), "/", CONFIG_LOCALE, NULL);
    }

    errno = 0;

    if (!setlocale(LC_ALL, ""))
    {
        fprintf(stderr, "Failed to set LC_ALL to native locale: %s\n",
                errno ? strerror(errno) : "Unknown error");
    }

    /* The C locale is guaranteed (sort of) to be available. */

    setlocale(LC_NUMERIC, "C");

    bindtextdomain(domain, dir);
    bind_textdomain_codeset(domain, DEFAULT_CODESET);
    textdomain(domain);

    free(dir);
#elif ENABLE_NLS && ANDROID
    defineHashTableLocale();     
#else
    return;
#endif
}

#ifdef ANDROID
// GJT: Yoink: http://stackoverflow.com/questions/779875/what-is-the-function-to-replace-string-in-c
char* str_replace(char *orig, char *rep, char *with) {
    char *result; // the return string
    char *ins;    // the next insert point
    char *tmp;    // varies
    int len_rep;  // length of rep
    int len_with; // length of with
    int len_front; // distance between rep and end of last rep
    int count;    // number of replacements

    if (!orig)
        return NULL;
    if (!rep || !(len_rep = strlen(rep)))
        return NULL;
    if (!(ins = strstr(orig, rep))) 
        return NULL;
    if (!with)
        with = "";
    len_with = strlen(with);

    for (count = 0; tmp = strstr(ins, rep); ++count) {
        tmp += ins - tmp;
        ins = tmp;
    }

    // first time through the loop, all the variable are set correctly
    // from here on,
    //    tmp points to the end of the result string
    //    ins points to the next occurrence of rep in orig
    //    orig points to the remainder of orig after "end of rep"
    tmp = result = malloc(strlen(orig) + (len_with - len_rep) * count + 1);

    if (!result)
        return NULL;

    while (1) {
        len_front = ins - orig;
        tmp = strncpy(tmp, orig, len_front) + len_front;
        tmp = strcpy(tmp, with) + len_with;
        orig += len_front + len_rep; // move to next "end of rep"
        if (--count) break;
        ins = strstr(orig, rep);
    }
    strcpy(tmp, orig);
    return result;
}

void defineHashTableLocale()
{
    // GJT: Redid everything, as gettext() does not work in Android NDK: https://github.com/android/platform_bionic/tree/master/libc
    char *dir = strdup(getenv("LANGUAGE")); // GJT: LANGUAGE is set on Java side
    char filename[11] = "po/";   
    strcat(filename, dir);
    strcat(filename, ".po");

    p_table = ght_create(INITIAL_HASH_SIZE);
    if ( p_table == NULL )
    {
        LOGE("Failed to create hash table!");
        return;
    }
    ght_set_rehash(p_table, TRUE);
    ght_set_heuristics(p_table, GHT_HEURISTICS_MOVE_TO_FRONT);
    
    fs_file fin;
    char line[MAXSTR];

    if ((fin = fs_open(filename, "r")))
    {
        //LOGI("DEBUG reading from %s", filename);
        while(fs_gets(line, sizeof (line), fin) != NULL)
        {
            char msgid[MAXSTR], msgstr[MAXSTR];
            
            if(strncmp(line, MSGID, MSGIDLEN) == 0)
            {
                strcat(msgid, strndup(line + MSGIDLEN, strlen(line)));
                while (fs_gets(line, sizeof (line), fin) != NULL && strncmp(line, MSGSTR, MSGSTRLEN) != 0)
                {
                    strcat(msgid, line);
                }
            }
            if(strncmp(line, MSGSTR, MSGSTRLEN) == 0)
            {
                strcat(msgstr, strndup(line + MSGSTRLEN, strlen(line)));                
                while (fs_gets(line, sizeof (line), fin) != NULL && strncmp(line, "\n", 1) != 0)
                {
                    strcat(msgstr, line);
                }
            }
            
            if( (msgid != NULL && strcmp(msgid, "\0") != 0) && (msgstr != NULL && strcmp(msgstr, "\0") != 0))
            {   
                char* clean_msgid = (char *)malloc(MAXSTR * sizeof(char));              
                char* clean_msgstr = (char *)malloc(MAXSTR * sizeof(char)); 
                
                if ( strncmp(msgid, "\"\"\n\"", 4) == 0)
                {      
                    /*
                    GJT: TODO lines with multiple breaks don't get translated
                    
                    char* removedIDQuotes = str_replace(msgid, "\"", "");
                    char* removedIDSlashes = str_replace(removedIDQuotes, "\\\\", "\\");
                    char* removedIDBreaks = str_replace(removedIDSlashes, "\n", "");

                    strcpy(clean_msgid, removedIDBreaks);

                    char* removedMsgQuotes = str_replace(msgstr, "\"", "");
                    char* removedMsgSlashes = str_replace(removedMsgQuotes, "\\\\", "\\");
                    char* removedMsgBreaks = str_replace(removedMsgSlashes, "\n", "");

                    strcpy(clean_msgstr, removedMsgBreaks);*/
                }
                else
                {
                    strcpy(clean_msgid, trim_quotes_and_whitespace(msgid));     
                    strcpy(clean_msgstr, trim_quotes_and_whitespace(msgstr));
                }
                
                if (ght_insert(p_table, clean_msgstr,
                         strlen(clean_msgid), clean_msgid) < 0)
                {
                    //LOGE("Duplicate entry found: %s", clean_msgid);
                }
                
                msgid[0] = msgstr[0] = 0;
            }
        }

        fs_close(fin);
    }
    else
    {
        if (!fs_exists(filename))
        {
            LOGE("Translation for %s does not exist", filename);
        }

        return;
    }
}

const char* gettext_by_parsing(const char *msgid)
{
#if ENABLE_NLS & !ANDROID
    const char *msgval = gettext(msgid);
#elif ENABLE_NLS & ANDROID
    char* msgstr = ght_get(p_table, strlen(msgid), msgid);
    
    if (msgstr == NULL || strcmp(msgstr, "") == 0 )
        return msgid; // GJT: Default to English
    return msgstr;
#else
    return msgid;
#endif
}

const char *get_translated_text(const char *msgid)
{
#if ENABLE_NLS
    char *msgstr;

    msgstr = gettext_by_parsing(msgid);

    return msgstr;
#else
    return msgid;
#endif
}
#endif

const char *sgettext(const char *msgid)
{
#if ENABLE_NLS && !ANDROID
    const char *msgval = gettext(msgid);
#elif ENABLE_NLS && ANDROID
    const char *msgval = gettext_by_parsing(msgid);
#else
    const char *msgval = msgid;
#endif

    if (msgval == msgid)
    {
        if ((msgval = strrchr(msgid, '^')))
            msgval++;
        else msgval = msgid;
    }
    return msgval;
}

#ifndef ANDROID
const char *get_local_text(const char *msgid)
{
#if ENABLE_NLS
    char *msgstr, *domain = textdomain(NULL);

    bind_textdomain_codeset(domain, "");
    msgstr = gettext(msgid);
    bind_textdomain_codeset(domain, DEFAULT_CODESET);

    return msgstr;
#else
    return msgid;
#endif
}
#endif

/*---------------------------------------------------------------------------*/
