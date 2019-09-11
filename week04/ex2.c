#include <stdio.h>

int main(int argc, char const *argv[]) {
  for(int i = 0; i < 5; i++)
  {
    fork();
    sleep(5);
  }
}

/*
Final output for 3 is

.
.
.
├─gnome-terminal-─┬─bash─┬─ex2─┬─ex2─┬─ex2───ex2
        │         │                 │      │     │     └─ex2
        │         │                 │      │     ├─ex2───ex2
        │         │                 │      │     └─ex2
        │         │                 │      └─pstree
        │         │                 └─3*[{gnome-terminal-}]

.
.
.

so, overall, 2^3 = 8 processes were created.


Final output for 5 is

─gnome-terminal-─┬─bash─┬─ex2─┬─ex2─┬─ex2─┬─ex2─┬─ex2───ex2
        │         │                 │      │     │     │     │     └─ex2
        │         │                 │      │     │     │     ├─ex2───ex2
        │         │                 │      │     │     │     └─ex2
        │         │                 │      │     │     ├─ex2─┬─ex2───ex2
        │         │                 │      │     │     │     └─ex2
        │         │                 │      │     │     ├─ex2───ex2
        │         │                 │      │     │     └─ex2
        │         │                 │      │     ├─ex2─┬─ex2─┬─ex2───ex2
        │         │                 │      │     │     │     └─ex2
        │         │                 │      │     │     ├─ex2───ex2
        │         │                 │      │     │     └─ex2
        │         │                 │      │     ├─ex2─┬─ex2───ex2
        │         │                 │      │     │     └─ex2
        │         │                 │      │     ├─ex2───ex2
        │         │                 │      │     └─ex2
        │         │                 │      └─pstree
        │         │                 └─3*[{gnome-terminal-}]




so, overall, 2^5 = 32 processes were created.
*/
