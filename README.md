# Introduction

[Neverball](http://neverball.org/) is an open-source and free ball-rolling game. It was designed to be "like" Super Monkey Ball, but it's about a thousand times better. It has been in development on the desktop for nearly a decade now.

Neverball ME, or "mobile edition," is the first public forray onto mobile platforms. This port is entirely for Android devices. It's currently in beta, and not yet available on the Android Market. The basic gameplay is functioning, but some of the graphics are a little warped, and the touchscreen interaction can sometimes be difficult.

Neverball ME is only available for Android devices running 2.1 (Eclair) and above. 

# How to Build

If you just want to play the game without installing it, you can! Simply type `adb install -r project/bin/MainActivity-debug.apk`. If you don't have `adb` installed, you could try emailing the .apk to your Gmail account, opening that attachment from your phone, and installing it there.

Neverball depends on SDL 1.2, so you should first familiarize yourself with [pelya's most awesome port for Android](https://github.com/pelya/commandergenius). Do _everything_ his readme says. 

Technically speaking, parts of pelya's port is provided in this fork. I have made additional modifications specific to Neverball ME. All you really ever need to do here is run `sh build.sh` and you should be good to go. You'll need ant, the Android SDK, the Android NDK, and everything else pelya's port requires if you intend to build the game.

I will try to keep this project as closely matched to pelya's SDL updates, as well as the continued updates to the official Neverball package.

# What's Not Working

The following aspects of the game, in no particular order, are either not working, not working well, or haven't been tested for Android:

1. Touchscreen: the pressing of buttons can be a bit difficult at times. You basically have to "double tap"--hard.
2. Localization: there's still some work to be done here. It's about 80% complete. One-liners are translated, but anything spanning more than one line is not.
3. Tablets: I have not tested the game on any Android tablet, because I don't have one! 
4. Neverputt: I have not yet tested this game. Frankly, it will probably only really work on tablets, given the way the game is played.
5. There's probably all sorts of issues if a call comes in, if the user hits the *Home* button, e.t.c.

# Gameplay & Documentation

The documentation for Neverball ME is located on this site's GitHub page: [http://gjtorikian.github.com/Neverball-ME](http://gjtorikian.github.com/Neverball-ME/).

# Credits

There are too many people to list! pelya, obviously, for the SDL 1.2 port to Android. rlk, parasti, Elviz, and everyone else dedicated to continuing work on Neverball.