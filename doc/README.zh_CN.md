## 目录结构

deepin-tweak 接受的插件目录必须具备以下结构:

- assets 目录

  存储图片等素材

- translations 目录

  存放 Qt 的翻译文件

- main.qml

  插件主界面

## 主界面

deepin-tweak 会加载插件的主界面到窗口中，主界面的 QML 不能是 Window 元素。

### 插件元信息

在 `main.qml` 中需要提供以下属性作为插件的元信息:

- displayName
- description
- version
- author
- icon

```qml
property string displayName: "Test Name"
property string description: "Test description"
property string version: "1.0.0"
property string author: "justforlxz"
property string icon: "icon.png"
```

## 调用接口

deepin-tweak 内置了执行命令、读写文件及 DBus 调用的接口。

### 执行命令

tweak 提供了 launcher 对象，可以调用 launcher.launch(<program>, [args]) 方法执行一个命令，并获取输出。

launcher.asyncLaunch(<program>, callback) 方法可以异步执行一个命令，并通过回调函数获取命令输出.

launcher.asyncLaunchWithArgs(<program>, <[args]>, callback) 方法可以异步执行一个命令，并通过回调函数获取命令输出.

### 读写文件

### DBus 调用

tweak 使用 nemo.dbus 为 qml 提供 DBus 调用的能力。

在 qml 文件中导入 `import Nemo.DBus 2.0`，并使用
tweak 使用 Nemo.DBus 为 qml 提供 DBus 调用的能力。

在 qml 文件中导入 `import Nemo.DBus 2.0`，并创建一个 DBusInterface 对象执行 DBus 调用。

DBusInterface 提供了 `service`、`iface` 和 `path` 属性用来初始化 DBus 连接。

```qml
DBusInterface {
  id: profiled
  service: 'org.kde.KWin'
  iface: 'org.kde.kwin.Effects'
  path: '/Effects'
}
```

在函数中调用  call 方法执行 DBus 调用。

```
profiled.call('loadEffect', ['blur']);
```

### 插件示例

```qml
import QtQuick.Layouts 1.7
import QtQuick 2.4
import org.deepin.dtk 1.0

RowLayout {
  property string displayName: "Test Name"
  property string description: "Test description"
  property string version: "1.0.0"
  property string author: "justforlxz"
  property string icon: "icon.png"
  Text {
      text: "input"
  }
  LineEdit {}
}
```

更多插件示例在 [demos](demos) 目录查看。
