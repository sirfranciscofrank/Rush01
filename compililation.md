# Rush01 — Compile & Test Cheat Sheet

Copy-paste blocks. Run everything from the `ex00` folder.

## 1. Go to the folder

```powershell
cd C:\Users\ADMin\Desktop\Rush01\ex00
```

## 2. Compile (exact command the graders use)

```powershell
cc -Wall -Wextra -Werror -o rush01 *.c
```

No output = success. It creates `rush01` (`rush01.exe` on Windows) from the
six source files: `main.c`, `ft_parse.c`, `ft_solve.c`, `ft_rules.c`,
`ft_views.c`, `ft_print.c`.

> **Windows note:** if you get `ld returned 5 exit status`, an old
> `rush01.exe` is still running or locked. Kill it, then recompile:
>
> ```powershell
> taskkill /IM rush01.exe /F
> ```

## 3. Valid inputs (should print a grid)

The subject example — must print **exactly** this grid:

```powershell
./rush01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
```

```
1 2 3 4
2 3 4 1
3 4 1 2
4 1 2 3
```

More solvable sets:

```powershell
./rush01 "2 3 1 2 2 2 3 1 2 1 2 2 2 4 3 1"
./rush01 "1 2 2 3 3 2 2 1 1 2 2 3 3 2 2 1"
```

## 4. Error inputs (every one must print exactly `Error`)

```powershell
./rush01
./rush01 "1 2" "3 4"
./rush01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2"
./rush01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 5"
./rush01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2  2"
./rush01 " 4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
./rush01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2 "
./rush01 "a 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
./rush01 "4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4"
./rush01 "1 2 3 4 4 3 2 1 1 2 3 4 4 3 2 1"
```

In order: no argument, two arguments, 15 values, digit out of range,
double space, leading space, trailing space, letter, impossible clues,
well-formatted but contradictory clues.

The strict parser is what catches the spacing cases: a valid input is
exactly 31 characters (16 digits, 15 single spaces), nothing more.

Evaluators sometimes also check the **exit status** right after a run:

```bash
echo $?
```

It must be `0` after a solved grid and `1` after any `Error` (bad
arguments, bad format, or unsolvable clues).

## 5. Check line endings like the graders do (Git Bash / Linux only)

```bash
./rush01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" | cat -e
```

Each line must end with `$` and nothing after the last digit
(no trailing space). On Windows you may see `^M$` — that's the Windows
console, not your program; on Linux it will be clean.

## 6. Norm check

```bash
norminette *.c
```

Every file must report `OK!`. What the norm cares about here: functions of
25 lines max, 5 functions per file max, no `for` loops, tab indentation,
and the 42 header at the top of each file **matching its filename** (that's
why the header line inside `ft_rules.c` says `ft_rules.c`, not `rules.c`).

## 7. Full clean rebuild + main test in one line

PowerShell:

```powershell
Remove-Item rush01.exe -ErrorAction SilentlyContinue; cc -Wall -Wextra -Werror -o rush01 *.c; ./rush01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
```

Git Bash / Linux:

```bash
rm -f rush01 && cc -Wall -Wextra -Werror -o rush01 *.c && ./rush01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
```

## 8. Before turning in — checklist

- [ ] Compiles with `cc -Wall -Wextra -Werror -o rush01 *.c` (zero warnings)
- [ ] Subject example prints the exact expected grid
- [ ] Every error input in section 4 prints `Error` + newline
- [ ] Only `*.c` files in `ex00/` (no `.exe`, no `a.exe`, no extra files)
- [ ] Norminette passes (functions ≤ 25 lines, ≤ 5 functions per file,
      no `for` loops, only `write`/`malloc`/`free` from libc)
