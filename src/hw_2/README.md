# 编译要求
## CMakelist

### 首先是用于产出二进制可执行编译产物的指令

- `add_executable(${PROJECT_NAME}_node src/hw_2_node.cpp)`

- `target_link_libraries` 默认配置即可

### 用于控制 msg 文件编译的指令

```cmake
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation # cmake macro 来引入用于编译 msg 文件的代码，使其不至于报错
  message_runtime # 同上？
)
```
<!-- 
```cmake
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES hw_2
 CATKIN_DEPENDS roscpp std_msgs message_runtime # 用于？
#  DEPENDS system_lib
)
``` -->

### 指定 msg 文件

```cmake
add_message_files(
  FILES
  test.msg
)
```

### 头文件生成

没有头文件其他软件包就不能共享自定义的消息格式了

```cmake
generate_messages(
  DEPENDENCIES
  std_msgs
)
```

头文件会生成在 `/devel/include/{Project Name}/` 下。

## package.xml

package.xml 也同样指定了ros软件包对依赖的需求。

```xml
  <!-- Use build_depend for packages you need at compile time: -->
  <build_depend>message_generation</build_depend>
  <!-- Use exec_depend for packages you need at runtime: -->
  <exec_depend>message_runtime</exec_depend>
```

> 不指定不会对编译产生影响

