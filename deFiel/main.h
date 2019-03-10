/*
* xiayebo
* 2019/3/10
*/
import console;
import fsys;
import fsys.config;
import fsys.file;
import fsys.log;

console.setTitle("deFile");

console.log("正在处理......");

function nowTime(){
	return tostring(time(num,format));
}

// 日志
var successLog = fsys.log("/res/log/success.txt");
var errorLog = fsys.log("/res/log/error.txt");

// 读取配置文件
var cfg = fsys.config("/res/config/");
// 默认
var foldePath = "n:/text/";
var fileName = "test";
var fileSuffix = ".test";
var frontTime = 0;
try{
	// 文件路径
	foldePath = cfg.deFile.config.foldePath;
	// 文件名可用能配符
	fileName = cfg.deFile.config.fileName;
	// 文件后缀
	fileSuffix = cfg.deFile.config.fileSuffix;
	// 设置要删除什么时间前的文件（单位：秒/s）
	frontTime = tonumber(cfg.deFile.config.frontTime);
	// 参数合法性
	if(frontTime<=0){
		errput("配置文件");
	}	
}catch(e){
	errorLog.printf("%s 配置文件出错",nowTime());
	return;
}
// 当前时间
var now2 = time(num,format);
// 要删除的创建文件之前的时间
now2 = tonumber(now2)-frontTime;
// 遍历目录
try{
	successLog.printf("%s ------------------开始------------------------",nowTime());
	fsys.enum( foldePath,
				fileName+fileSuffix, // 指定查询文件名,支持windows掩码
				function(dir,filename,fullpath,findData){ // 指定触发器
					if(filename){ 
           				//console.log("发现文件：",fullpath );
           				file = fsys.file(fullpath,"r");
           				// 文件创建时间
           				tm = file.getTime();
           				// 关闭读要先关闭，不然后面删除不了
           				file.close();
           				tm = tonumber(tm.write);
           				console.log("....");
           				if(tm<=now2){
           					fsys.delete(io.fullpath(fullpath));
           					console.log("删除："+fullpath);
           					successLog.printf("%s 成功删除:"+fullpath,nowTime());
           				}
           				
					}
				}
	); 	
}
catch(e){
	errorLog.printf("%s 目录异常或无相关要删除的文件",nowTime());
}

//关闭日志
successLog.close();
errorLog.close();
console.log("完成....");