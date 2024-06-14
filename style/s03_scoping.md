# Scoping

These are rules regarding scoping. This document is inspired by the *[Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html#Scoping)*.

## Namespaces

Namespaces are useful to avoid code name collisions. Therefore, most of the code should be in a namespace. 

A namespace should end with a comment that says which namespace it is.
```cpp
namespace MyNamespace {

} // namespace MyNamespace
```

You should never use `using namespace` or a namespace aliases like `namespace baz = ::foo::bar::baz;`.
The only point of those is to reduce the amount of code we write but in order to reduce confusion around namespaces, we should simply write them the long way.

For nested namespaces, or namespaces inside other namespaces, we should use this type of definition.
```cpp
namespace A::B::C {

}
```
Also, we should avoid to have more than three nested namespace levels. This will make sure using features wont require too much typing.


### Local Variables

For any local variable, the declaration should be done at the same time as the initialization. They should be declared close to their use.