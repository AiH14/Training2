#include <stdio.h>
#include <stdint.h>


#include app.h
#include camerasetting.h

static bool is_initialized = false;

void app_setcolor()
{
    CHANGE_COLOR color = {0};
    
    color.type = 1;
    color.status = 2;

    camera_set_color(color);
}

void app_setsize()
{
    CHANGE_SIZE size = {0};

    size.width = 3;
    size.length = 4;
    
    camera_set_size(size);
}

void app_setf()
{
    CHANGE_F f = {0};

    f.f = 5;
    f.sspeed = 6;
    
    camera_set_f(f);
}

void app_start()
{
    if(false == is_initialized)
    {
        camera_initialize();
        is_initialized = true;
    }
}

int app_appendall(bool onoff)
{
    int ret = 0;

    ret = camera_append_setting(COLER,onoff);
    if (ret != 0)
    {
        return(ret);
    }
    ret = camera_append_setting(SIZE,onoff);
    if (ret != 0)
    {
        return(ret);
    }
    ret = camera_append_setting(F,onoff);
    
    return(ret);
}

int app_appendcolor(bool onoff)
{
    int ret = 0;
    
    ret = camera_append_setting(COLER, onoff);
    return(ret);
}

int app_appendsize(bool onoff)
{
    int ret = 0;
    
    ret = camera_append_setting(SIZE, onoff);
    return(ret);
}

int app_appendf(bool onoff)
{
    int ret = 0;
    
    ret = camera_append_setting(F, onoff);
    return(ret);
}

int app_change_settings()
{
    int ret = 0;
    ret = camera_change_settings();
    return(ret);
}

int main(int argc, char *argv[]) {
    int setting = 0;
    bool append_onoff;
    int ret = 0;
    
    if (argc < 2) {
        printf("引数が不足しています。\n");
        return 1;
    }
    app_start();

    /* set only */
    if (argc == 2)
    {
        setting = atoi(argv[1]); // コマンドライン引数を整数に変換する
        switch(setting)
        {
            case 1: // 色彩設定
                app_setcolor();
                break;
            case 2: // サイズ設定
                app_setsize();
                break;
            case 3: // F値設定
                app_setf();
                break;
            case 4:
                ret = app_change_settings();
                break;
            default:
                printf("サポートされていない引数です。\n");
                ret = 1;
                break;
        }
    }
    else if(argc == 3) /* Append Only */
    {
        setting = atoi(argv[1]); // コマンドライン引数を整数に変換する
        append_onoff = atoi(argv[2]); // コマンドライン引数を整数に変換する
        switch(setting)
        {
            case 1:
                ret = app_appendcolor(append_onoff);
                break;
            case 2:
                ret = app_appendsize(append_onoff);
                break;
            case 3:
                ret = app_appendf(append_onoff);
                break;
            case 4:
                ret = app_appendall(append_onoff);
                break;
            default:
                printf("サポートされていない引数です。\n");
                ret = 1;
                break;
        }
    }

   return(ret);
}
