# Comments

This is how we should write comments. This document is inspired by the *[Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html#Comments)*.

## Comment Style

We will use `//` for small one line comments. We will use `/* */` for longer, multiline comments.

```cpp
/**
* This function take in 2 parameters of type int.
* It then add them and return the result
*/
int doSomething(int a, int b) {
    // do the addition
    int c = a + b;
    // return the result
    return c;
}
```


## File Comments

Each file should start with a file comment. This comment should contain the file name, the project name, a description of the file (what is it, what does it contain, why does it exist, etc), the author's name and a licensing boilerplate.

```cpp
/**
 * @file [my_file.h]
 * This file is part of [Project Name]
 * 
 * [Description of the file]
 * 
 * Copyright (c) [20XX]-present by [the author full name].
 * 
 * [Licensing]
 * 
 */
```

Here is what it should look like for the GodHunter Project:

```cpp
/**
 * @file [my_file.h]
 * This file is part of the GodHunter Engine
 * 
 * [Description of the file]
 * 
 * MIT License
 * 
 * Copyright (c) 2023 GeoffroiHenquin
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 */
```


## Struct and Class Comments

Each class or struct should start with a comment that explains what it is, what it represent, how it can/should be used, etc.

```cpp
/**
 * [Class or Struct] - [Class Name]
 * 
 * [Description of the class]
 * 
 * [How it could be used]
 */
```


## Function Comments

Each function should start with a comment that describe what the function does and how to use it.

```cpp
/**
 * [Description of the function]
 *
 * @param [parameter name] [Description of the parameter]
 * @return [value that is returned]
 */
```


## Variable Comments

Each class data member and each global variable should have a single line comment explaining the variable, what it represent, how it's used and why.


## TODO Comments

Where a task needs to be done at a future date, a single line comment should be written,  indicating the task needed.

```cpp
// TODO: Fix bug where -1 is returned.
```