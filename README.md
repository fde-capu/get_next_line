## get_next_line
### by fde-capu
42SP get_next_line reads from file descriptor one line at the time

Reading a line on a fd is way too tedious.

    • Calling your function get_next_line in a loop will then allow you to read the text
    available on a file descriptor one line at a time until the EOF.
    • Make sure that your function behaves well when it reads from a file and when it
    reads from the standard input.
    • libft is not allowed for this project. You must add a get_next_line_utils.c file
    which will contain the functions that are needed for your get_next_line to work.
    • Your program must compile with the flag -D BUFFER_SIZE=xx. which will be used
    as the buffer size for the read calls in your get_next_line. This value will be
    modified by your evaluators and by moulinette.
    • Compilation will be done this way : gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32
    get_next_line.c get_next_line_utils.c
    • Your read must use the BUFFER_SIZE defined during compilation to read from
    a file or from stdin.
    • In the header file get_next_line.h you must have at least the prototype of the
    function get_next_line.
    • We consider that get_next_line has an undefined behavior if, between two calls,
    the same file descriptor switches to a different file before EOF has been reached on
    the first fd.
    • lseek is not an allowed function. File reading must be done only once.
    • Finally we consider that get_next_line has an undefined behavior when reading
    from a binary file. However, if you wish, you can make this behavior coherent.
    • Global variables are forbidden.

---

*this project is part of the 42 São Paulo cursus*

---

Copyright 2020 fde-capu

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
