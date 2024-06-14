# Header Files

These are rules regarding header files and their inclusion. This document is inspired by the *[Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html#Header_Files)*.

## The #define Guard

In a C++ program, objects can only be defined once. Therefore, each header file should contain a way to only be included once.

There are 2 ways to achieve this:

1. Add at the beginning of each header file the line:
```cpp
#pragma once
```
2. Add in each header files a define guard such as:
```cpp
#ifndef PROJECTNAME_PATH_FILE_H_
#define PROJECTNAME_PATH_FILE_H_

...

#endif  // PROJECTNAME_PATH_FILE_H_
```

The option 1 (`#pragma once`) is not in the standard and does not act the same for every compilers. Therefore, the option 2 (`define guard`) should be prioritized.


## Include What Is Used

Any source and header files should include directly what they use. In a scenario where `A.h` include `B.h` and `B.h` include `C.h`, if `A.h` uses features from `C.h`, it should include `C.h`. This way, if we ever decide to remove `B.h` from `A.h`, The features from `C.h` will still work.

Any source and header files should avoid what they dont use. If `A.h` does not use any features from `B.h`, it should not include it.


## Names and Order of Includes

Files should be included in a certain order:

1. Related header 
    > This would be `#include "A.h"` in `A.cpp`.
2. C system headers
    > This would be files with angle brackets and the .h extension like `<unistd.h>` or `<stdlib.h>`.
3. C++ standard library headers
    > This would be files without the file extension like `<algorithm>` or `<cstddef>`.
4. Third parties libraries headers
    > This would be files from libraries like `<SDL.h>`.
5. Project headers
    > These would be your project's headers.
6. Exceptions
    > Exceptions are optionals. They can appear when the inclusion of a file must follow a certain condition. As an example, the file `windows.h` should only be included if the macro `_WIN32` is defined. Each exception should have a comment to explain it.

Of course, within each category, the files should be included in alphabetical order.

So the result should look like this:
```cpp
// Related header
#include "MyClass.h"

// C system headers
#include <stdlib.h>
#include <unistd.h>

// C++ standard library headers
#include <algorithm>
#include <cstddef>

// Third party libraries headers
#include <SDL.h>

// Project headers
#include "A.h"
#include "B.h"
#include "C.h"

// Exceptions
// The file windows.h can only be used on Windows
#ifdef _WIN32
#include <windows.h>
#endif //_WIN32
```