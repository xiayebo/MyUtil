# deFile

自动删除文件工具，它可以帮我们做到设置时间定时删除文件，例如一个文件我们设置自它生成后的10天后删除，那么这个时候就可以帮我们做到10天后删除掉这些文件（可以使用通配符）. 处理服务的一些日志文件或缓存文件等！

##### 目录结构
deFile.exe
--├- res
---├- config //配置目录
----├- deFile.table //配置文件
---├- log //日志目录
----├- error.txt //错误日志
----├- success.txt //处理日志

#####  配置
```sh
# foldePath 文件夹路径
# fileName 文件名（可用通配符）
# fileSuffix 文件后缀（要带上点.）
# frontTime 时间秒/S 删除当前时间前 n 秒(你设置的)创建的某文件(设置的文件)
# 例：
{config={frontTime=200;foldePath="d:/test/";fileName="text*";fileSuffix=".txt"}}
```

配置好后，最后设置好系统的定时任务管理就好了..

