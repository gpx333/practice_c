/*************************************************************************
	> File Name: function.c
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年10月04日 星期四 10时57分05秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <stdarg.h>

int write_Pi_log (char *PiHealthLog, const char *format, ...);
//向文件写日志
//host_t="192.168.1.40";
//write_pi_log(PiHealthLog, "Connection to %s success\n", host_t);
//PihealthLog是日志文件的路径。

int get_conf_value(char *path_name, char *key_name, char *value);
// 从一个配置文件中读取某个配置的值
// strstr
// strlen
// strncpy
// fopen
// getline
///path_name为配置文件的路径。key_name是需要照的配置字段名，value是配置的值存放变量。
//host=192.168.1.40

int write_Pi_log(char *PiHealthLog, const char *format, ...) {
    FILE *fp;
    fp = fopen(PiHealthLog, "a+");
    fprintf(fp, "%s", __DATE__);
    fprintf(fp, "%s", __TIME__);
    va_list arg;
    va_start(arg, format);
    vfprintf(fp, format, arg);
    va_end(arg);
    fclose(fp);
}

int get_conf_value(char *path_name, char *key_name, char *value) {
    FILE *fp;
    if ((fp = fopen(path_name, "r")) == NULL) {
        printf("%s not exist\n", path_name);
        exit(0);
    }
    size_t len = 0;
    char *line = NULL;
    ssize_t read;
    int key_len = strlen(key_name);
    while ((read = getline(&line, &len, fp)) != -1) {
        if(strstr(line, key_name) != NULL) {
            if (line[key_len] == '=') {
                strncpy(value, &line[key_len + 1], read - key_len - 1);
                key_len = strlen(value);
                value[key_len - 1] = '\0';
                fclose(fp);
                return 1;
            } 
        }
    }
    fclose(fp);
    return 0;
}

int main() {
    char str[100], key[10] = {"port1"};
    get_conf_value("./PiHealthyLog/PiHealthLog.conf", key, str);
    printf("%s\n", str);
    return 0;
}
