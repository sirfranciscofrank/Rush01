# Rush01 — Skyscraper Puzzle Solver

## The puzzle

You have a 4x4 grid. Every cell gets a "box" (skyscraper) of height 1, 2, 3 or 4.

Two rules:

1. **Latin square rule** — each row and each column contains every height
   exactly once (like Sudoku: no duplicates in a row or column).
2. **Visibility rule** — the 16 numbers given on the command line are *clues*.
   Each clue says how many boxes you can see when looking along a row or a
   column from outside the grid. A taller box hides every shorter box behind it.

Example for one line `1 2 3 4`:
- From the **left** you see 4 boxes (each one is taller than the previous).
- From the **right** you see only 1 (the 4 hides everything).

For the line `2 1 4 3`: from the left you see the 2, the 1 is hidden, the 4 is
visible, the 3 is hidden → **2 visible**.

## Input format

```
./rush01 "c1t c2t c3t c4t  c1b c2b c3b c4b  r1l r2l r3l r4l  r1r r2r r3r r4r"
```

The 16 clues arrive in this order (we store them in `clues[0]`..`clues[15]`):

| Index in `clues[]` | Meaning                          |
|--------------------|----------------------------------|
| 0–3                | columns 1–4 seen from the **top**    |
| 4–7                | columns 1–4 seen from the **bottom** |
| 8–11               | rows 1–4 seen from the **left**      |
| 12–15              | rows 1–4 seen from the **right**     |

Anything that is not exactly 16 digits (`1`–`4`) separated by single spaces is
an error → print `Error`.

## How the program flows

```
main
 ├─ ft_init_grid   fill grid with 0 (0 = empty cell)
 ├─ ft_parse       validate the string, extract the 16 clues
 ├─ ft_solve       backtracking: try to fill the grid
 └─ ft_print_grid  print the solution (or "Error" if parse/solve failed)
```

The grid is a single array `int grid[16]`. Cell (row, col) lives at
`grid[row * 4 + col]`. That's why you see `pos / 4` (row) and `pos % 4`
(column) everywhere: `pos` is a number from 0 to 15 that walks the grid
left-to-right, top-to-bottom.

---

## File by file

### main.c

- `ft_init_grid` — sets all 16 cells to `0`, meaning "empty".
- `main` — checks there is exactly **one** argument (`argc != 2` → Error),
  parses it, launches the solver from position 0, prints the result.
  Returns `1` on error, `0` on success.

### parse.c

- `ft_strlen` — string length (we can't use the libc one, only `write`,
  `malloc`, `free` are allowed).
- `ft_is_valid_format` — a valid input is **exactly 31 characters**:
  16 digits + 15 spaces. Even positions (0, 2, 4, …) must be a digit `'1'`–`'4'`,
  odd positions must be a single space. Anything else → invalid.
- `ft_parse` — once the format is validated, converts each digit character to
  an int (`str[i * 2] - '0'`) and stores it in `clues[]`.

### solve.c — the heart of the program (backtracking)

- `ft_solve(grid, pos, clues)` — tries to fill cell `pos`, then recursively
  the next one:

  1. If `pos == 16`, every cell is filled and every check passed → **solved**,
     return 1.
  2. Otherwise try each value 1, 2, 3, 4 in that cell:
     - Skip it if it already appears in this row or column (`ft_is_safe`).
     - Place it, and if the clue checks still hold (`ft_check_partial`),
       recurse on `pos + 1`.
     - If the recursion succeeds, propagate the 1 all the way up.
     - If it fails, **undo** the cell (`grid[pos] = 0`) and try the next
       value. This "undo and try something else" is the *backtracking*.
  3. If no value works, return 0 so the previous cell tries its next value.

  Because values are always tried in order 1→4 and cells in order 0→15, the
  first solution found is always the same one — that's the "first solution you
  encounter" the subject asks for.

- `ft_check_partial(grid, pos, clues)` — we don't wait until the grid is full
  to check clues. As soon as a **row is complete** (we just filled its last
  cell, `col == 3`) we verify that row's two clues; as soon as a **column is
  complete** (`row == 3`) we verify that column's two clues. If a check fails
  we abandon this branch immediately instead of filling the rest of the grid
  for nothing. This pruning is what makes the solver fast.

### rules.c — the checks

- `ft_is_safe(grid, pos, value)` — scans the row and the column of `pos`;
  returns 0 if `value` is already there (Latin square rule).
- `ft_check_row(grid, row, clues)` — copies the row, counts visible boxes from
  the left and (via a reversed copy) from the right, compares with
  `clues[8 + row]` and `clues[12 + row]`.
- `ft_check_col(grid, col, clues)` — same idea for a column: visible from the
  top vs `clues[col]`, from the bottom vs `clues[4 + col]`.

### lines.c — small helpers

- `ft_get_row` / `ft_get_col` — copy a row or a column into a 4-int array so
  the counting code works the same for both.
- `ft_reverse` — reverses a 4-int line. Looking from the right is just looking
  from the left at the reversed line.
- `ft_count_view` — **the visibility algorithm.** Walk the line keeping track
  of the tallest box seen so far (`max`). Every time a box is taller than
  `max`, it is visible: count it and update `max`.

  ```
  line = 2 1 4 3
  2 > 0 → visible (count=1, max=2)
  1 < 2 → hidden
  4 > 2 → visible (count=2, max=4)
  3 < 4 → hidden
  → 2 visible boxes
  ```

### ft_print.c — output

- `ft_putchar` / `ft_putstr` — wrappers around `write` (the only allowed
  output function).
- `ft_print_error` — writes `Error\n`.
- `ft_print_grid` — prints the 16 cells as 4 lines of 4 digits separated by
  spaces (no trailing space, newline at the end of each row).

---

## Walkthrough of one solve step

Clues: `"4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"`.

Column 1 seen from the top must show **4** boxes → the column has to be
`1 2 3 4` (strictly increasing is the only way to see all 4). The solver
doesn't "know" this as a rule, but backtracking discovers it: any other
arrangement fails `ft_check_col` and gets undone.

Cell by cell it tries 1 in `grid[0]` → safe → not end of row/col → move on;
1 in `grid[1]` → duplicate in row → try 2 → safe → … and so on. Each dead end
rolls back to the last choice point. The final grid:

```
1 2 3 4
2 3 4 1
3 4 1 2
4 1 2 3
```

## Compile & run

```
cc -Wall -Wextra -Werror -o rush01 *.c
./rush01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
```

Errors (wrong argument count, bad format, impossible clues) print `Error`
followed by a newline.

## Questions an evaluator might ask

- **Why `pos / 4` and `pos % 4`?** The grid is a flat 16-int array; division
  gives the row, modulo gives the column.
- **What is backtracking?** Depth-first trial and error: place a value, go
  deeper; on failure, erase it and try the next value. Guaranteed to find a
  solution if one exists, because it explores every consistent possibility.
- **Why check clues before the grid is full?** Pruning. A completed row/column
  that already violates its clues can never lead to a solution, so we cut the
  branch early.
- **Why is the first solution deterministic?** Cells are filled in a fixed
  order and values tried in a fixed order (1→4), so the search always visits
  candidate grids in the same sequence.
- **Why no malloc?** Everything fits in fixed-size stack arrays
  (`int grid[16]`, `int clues[16]`, `int line[4]`), so dynamic allocation is
  unnecessary.
