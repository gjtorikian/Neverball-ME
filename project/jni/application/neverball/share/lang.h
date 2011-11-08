/*
 * Copyright (C) 2006 Jean Privat
 *
 * this file is  free software; you can redistribute  it and/or modify
 * it under the  terms of the GNU General  Public License as published
 * by the Free  Software Foundation; either version 2  of the License,
 * or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT  ANY  WARRANTY;  without   even  the  implied  warranty  of
 * MERCHANTABILITY or  FITNESS FOR A PARTICULAR PURPOSE.   See the GNU
 * General Public License for more details.
 */

#ifndef LANG_H
#define LANG_H

#ifdef ANDROID
// GJT: Wha? Why is this needed here? Chicken before the egg problems? None of the Android L10N
// functions are defined without it.
#include <android_support.h>
#endif

#if ENABLE_NLS && !ANDROID
#include <libintl.h>

#define _(String)   gettext(String)
#define L_(String)  get_local_text(String)

#elif ENABLE_NLS && ANDROID
// GJT: Android does not support locales on the C level
// http://groups.google.com/group/android-ndk/msg/1a5248f31920638
#include <ght_hash_table.h>

//GJT: Should be a power of 2, and there's ~400 text entries
#define INITIAL_HASH_SIZE 512
#define MSGID  "msgid "
#define MSGIDLEN 6
#define MSGSTR "msgstr "
#define MSGSTRLEN 7

ght_hash_table_t* p_table;

#define _(String)   gettext_by_parsing(String)
#define L_(String)  get_translated_text(String)
void defineHashTableLocale();

#else

#define _(String)   (String)
#define L_(String)  (String)

#define ngettext(msgid, msgid_plural, n) ((n) == 1 ? (msgid) : (msgid_plural))

#endif /* ENABLE_NLS */

/* No-op, useful for marking up strings for extraction-only. */
#define N_(String)   String

/*---------------------------------------------------------------------------*/

void lang_init(const char *domain);

const char *sgettext(const char *);
const char *get_local_text(const char *);

/*---------------------------------------------------------------------------*/

#endif
