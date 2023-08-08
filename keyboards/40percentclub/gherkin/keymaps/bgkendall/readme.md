# Gherkin/bgkendall

 * **Author** — [bgkendall](https://github.com/bgkendall/qmk_firmware)
 * **Hardware** — [Gherkin](http://www.40percent.club/2016/11/gherkin.html) customised
   to add rotary encoder and RGB indicator lights
 * **Features** — Modified [Averak] primary layer; macOS focused


## Building

### Requires

 * `users/bgkendall/bgk_encoder.h`
 * `users/bgkendall/bgk_encoder.c`
 * `users/bgkendall/bgk_keycommands.h`
 * `users/bgkendall/bgk_rgb.h`
 * `users/bgkendall/bgk_rgb.c`

### Command

    qmk compile -kb 40percentclub/gherkin -km bgkendall


## Layers

 1. **AVERAK** — adaption of [Averak] Mod-HM/FY/OIU to account for 30% layout.
 2. **QWERTY** — mostly standard QWERTY layout with adjustments for 30% layout and P moved
    to Semicolon location (to keep the Backspace the same on both QWERTY and Averak).
 3. **NUMBER** — Numbers and Shift+number symbols (@, #, etc.) plus common punctuation.
 4. **SYMBOL_AV** — Symbols in mnemonic locations (see below) for Averak layer.
 5. **SYMBOL_QW** — Symbols in mnemonic locations (see below) for QWERTY layer.
 6. **NAVIGATION** — Cursor and mouse control
 7. **FUNCTION** — F1–10, special (Mac) character shortcuts, Caps Lock.
 8. **META** — Keyboard options, including reset and backlight on/off/breathe.

For a full layout visualisation, load `kle/gherkin.json` into
[Keyboard Layout Editor](http://www.keyboard-layout-editor.com/), or `keymap.json` can be
uploaded to [QMK Configurator](https://config.qmk.fm/).


## Symbol Mnemonics

All the symbols are represented by a mnemonic tied to the alpha keys. The locations will
change depending on whether the base keyboard is Averak or QWERTY.

| Symbol | Symbol Name              | Letter | Mnemonic |
| :----: | :----------------------- | :----: | :----------------------------------------------------------------------- |
|   ~    | Tilde                    |   N    | e**Ñ**e                                                                  |
|   \`   | Back-tick                |   T    | Back-**T**ick                                                            |
|   -    | Hyphen/Minus  | B or<br>H or<br>M | **B**ar (not QWERTY as B is layer key)<br>**H**yphen (not Averak as H is layer key)<br>**M**inus |
|   _    | Underscore               |   U    | **U**nderscore                                                           |
|   =    | Equals                   |   E    | **E**quals                                                               |
|   +    | Plus                     |   P    | **P**lus                                                                 |
|   \[   | Left Bracket             |   F    | Top of **F** ≈ ⊏ ≈ \[                                                    |
|   \]   | Right Bracket            |   J    | **J** looks like bottom of \]                                            |
|   {    | Left Brace               | Space  | None — convenient location on keyboard next to }                         |
|   }    | Right Brace              | Enter  | Return symbol vaguely like } — convenient location on keyboard next to { |
|   \\   | Backslash                |   W‡   | **W** starts with a backslash (**\\**/\\/)                               |
|   \|   | Pipe                     |   I    | **I** ≊ \|                                                               |
|   ;    | Semicolon                |   O    | **o** ≈ ⦁ ≈ half a colon                                                 |
|   :    | Colon                    |   K    | [**K**]olon                                                              |
|   ‘    | Apostrophe/Single Quote  |   A    | **A**phostrophe                                                          |
|   "    | Double Quote             |   Q    | **Q**uote                                                                |
|   ,    | Comma                    |   R    | **r** looks a bit like a rotated ,                                       |
|   <    | Less Than                |   L    | **L**ess than                                                            |
|   .    | Dot/Full Stop/Period     |   D    | **D**ot                                                                  |
|   >    | Greater Than             |   G    | **G**reater than                                                         |
|   /    | (Forward) Slash          |   S    | **S**lash                                                                |
|   ?    | Question Mark            |   Y    | Why?                                                                     |

For a visualisation, load `kle/gherkin-mnemonic-symbol-layer.json` into
[Keyboard Layout Editor](http://www.keyboard-layout-editor.com/).


## Encoder

The `bgk_encoder` library allows rotary encoder actions to be easily defined in the same
way as key layouts, including layer switching. The encoder has the following behaviour on
the different layers (anti-clockwise/clockwise):

 1. AVERAK — cursor right/left or up/down (axis is toggled by FUNCTION+F or META+Y)
 2. QWERTY — cursor right/left or up/down (axis is toggled by FUNCTION+G or META+O)
 3. NUMBER — display brightness up/down
 4. SYMBOL_AV — volume up/down
 5. SYMBOL_QW — volume up/down
 6. NAVIGATION — mouse wheel up/down
 7. FUNCTION — zoom in/out (Cmd+=/Cmd+-)
 8. META — backlight brightness up/down



[Averak]: https://www.reddit.com/r/MechanicalKeyboards/comments/ow4ve1/introducing_averak_a_very_average_layout/
