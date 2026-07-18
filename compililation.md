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

No output = success. It creates `rush01` (`rush01.exe` on Windows).

> **Windows note:** if you get `ld returned 5 exit status`, an old
> `rush01.exe` is still running or locked. Fix it, then recompile:
>
> ```powershell
> taskkill /IM rush01.exe /F
> ```

## 3. Valid inputs (should print a grid)

```powershell
./rush01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
```

Expected:

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

## 5. Check line endings like the graders do (Git Bash / Linux only)

```bash
./rush01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" | cat -e
```

Each line must end with `$` and nothing after the last digit
(no trailing space). On Windows you may see `^M$` — that's the Windows
console, not your program; on Linux it will be clean.

## 6. Full clean rebuild + main test in one line

PowerShell:

```powershell
Remove-Item rush01.exe -ErrorAction SilentlyContinue; cc -Wall -Wextra -Werror -o rush01 *.c; ./rush01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
```

Git Bash / Linux:

```bash
rm -f rush01 && cc -Wall -Wextra -Werror -o rush01 *.c && ./rush01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
```

## 7. Before turning in — checklist

- [ ] Compiles with `cc -Wall -Wextra -Werror -o rush01 *.c` (zero warnings)
- [ ] Subject example prints the exact expected grid
- [ ] Every error input in section 4 prints `Error` + newline
- [ ] Only `*.c` files in `ex00/` (no `.exe`, no `a.exe`, no extra files)
