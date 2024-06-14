# Naming Rules

This is how we're going to name things. This document is inspired by the *[Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html#Naming)* and the video *[Naming Things in Code](https://www.youtube.com/watch?v=-J3wNP6u5YU&ab_channel=CodeAesthetic)*. 

## General Naming Rules

Avoid abbreviations unless its a known abbreviation or its very obvious what it is.

```cpp
int ci; // Bad: Too unclear
int current_item; // Good: tells what it's stand for
```

Avoid names that are too long or too verbose.

```cpp
std::string the_name_of_the_application; // Bad: it's too long
std::string application_name; // Good: shorter but still give the same information
```

When needed, add units to variable names.

```cpp
int delay; // Bad: it's unclear if it's in seconds, milliseconds or something else
int delay_seconds; // Good: its clear that it's in seconds
```

Avoid generic words like base, abstract, utils, etc.

```cpp
class Car : CarBase { // Bad
}

class Car : Vehicule { // Good
}
```


## File Names

File names should be all lowercase and can include underscores (_). A file name should look like this: `my_own_class.h`.

The extension should be `.h` for header files, `.c` for C files and `.cpp` for C++ files. Files that designed to be included at specific places should end in `.inc`.

## Type Names

Type names start with a capital letter and have a capital letter for each new word, with no underscores (_).

```cpp
class MyOwnClass {};
struct MyOwnStruct {};
enum MyOwnEnum {};
typedef int MyOwnType;
```

## Variable Names

### Common Variable names

These are the variable declared in functions. They are in snake_case (all lowercase with underscore between words).

```cpp
std::string table_name;
```

### Function Parameter names

These are the variable declared in class. They are in snake_case (all lowercase with underscore between words) with an underscore at the end.

```cpp
int my_parameter_;
```

### Class Data Members

These are the variable declared in class. They are in snake_case (all lowercase with underscore between words) with the prefix `m_`.

```cpp
std::string m_table_name;
```

### Struct Data Members

These are the variable declared in structs. They are in snake_case (all lowercase with underscore between words).

```cpp
int num_entries;
```

### Global Variable names

These are the variable declared globaly (not in a function or a class). They are in snake_case (all lowercase with underscore between words) with the prefix `g_`.

```cpp
int g_my_variable;
```

### Constant Names

These are the constant. They are in PascalCase (all lowercase except for the first letters of each words) with the prefix `k`. In case you have to use a dot or dash, replace it with an underscore.

```cpp
const int kDaysInAWeek = 7;
const int kAndroid8_0_0 = 24;  // Android 8.0.0
```


## Function Names

Functions should be in camelcase (no spaces or underscores, Each word start with an uppercase except the first one).

```cpp
void doSomething();
int getData();
```


## Namespace Names

Namespaces should be all lowercase and in one word.

```cpp
namespace mynamespace {};
namespace osspecific {};
```


## Enumerator Names

The values in an enumerator should be in Pascalcase (no spaces or underscores, Each word start with an uppercase).

```cpp
enum DataType {
    Static = 0,
    Dynamic = 1,
    OtherType = 2
};
```


## Macro Names

Macros should be all uppercase with underscores (_). When possible, the Macro should start with the project name in order to avoid name collision with macros from libraries.

```cpp
#define PROJECTNAME_MY_MACRO
```