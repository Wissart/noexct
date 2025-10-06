# NoExCT

`NoExCT` - flexible and extensible testing framework for small or pet projects

## Features

* Easy manage tests:
  NoExCT automaticaly run your tests, eliminating the need for manual registration
* Base set of assertions:
  NoExct provides a basic set of assertions, such as equality, inequality, exceptions
* Custom asserions:
  You can define your own assertions
* Fixtures:
  Provide fixtures generation for suites or cases  
* Flexible report system:
  You can define your own reporter or use default(Console) reporter
* Minimum dependcies:
  You need only standart lib


## Integration

[test_engine.h](https://github.com/Wissart/noexct/blob/main/include/noexct/test_engine.h) is the single required file. You need to add

```cpp
#include <noexct/test_engine.h>
```

to the files with tests, and you can use all features of framework

### Requirements

To be able to use `NoExCT`, users must provide a full-featured compiler that supports at least C++ 17.

The code is known to work on the following compilers:
* Visual studio 2019 (or later) on Windows

### CMake

To use `NoExCT` from a `CMake` project, just link an existing target to the `NoExCT::NoExCT` alias.

You can use choose any ways to use framework in your project fetching( as in `FetchContent`), embedding(as in `add_subdirrectory`), locating(as in `find_package`)

#### Build Shared Library

As an alternative if you want to switch a static or shared version of freamework use `-DNOEXCT_BUILD_SHARED_LIBS=ON/OFF`.

## Examples

Here are some examples for show how to use this test framework

You may want to:
- Browse the [standalone example files](https://github.com/Wissart/noexct/tree/main/examples)

### Base example to use

``` cpp
#include "noexct/test_engine.h"

TEST_SUITE(SUITE_NAME)

TEST_CASE(PASS_CASE){
    ASSERT_EQ(2,2)
}

TEST_CASE(FAIL_CASE){
    ASSERT_EQ(2,1)
}

int main(){
    RUN_ALL_TESTS()
}
```

## Contributing

1. Fork the repository
2. Create a feature branch: `git checkout -b feature/new-feature`
3. Commit changes: `git commit -am 'Add new feature`
4. Push to the branch: `git push origin feature/new-feature`
5. Submit a pull request

## License

BSD 3-Clause License - see [LICENSE](LICENSE) file for details.