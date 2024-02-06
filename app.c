#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


#include "app.h"
#include "camerasetting.h"

static bool is_initialized = false;
static bool chenge_end = false;
static bool end_judge = false;

void app_setcolor(int colorvalue)
{
    CHANGE_COLOR color = {0};

    if(colorvalue == 0)
    {
        color.type = 1;
        color.status = 2;
    }
    else if(colorvalue == 1)
    {
        color.type = 0;
        color.status = 0;
    }
    camera_set_color(color);
}

void app_setsize(int sizevalue)
{
    CHANGE_SIZE size = {0};

    if(sizevalue == 0)
    {
        size.width = 3;
        size.length = 4;
    }
    else if(sizevalue == 1)
    {
        size.width = 0;
        size.length = 0;
    }
    camera_set_size(size);
}

void app_setf(int fvalue)
{
    CHANGE_F f = {0};

    if(fvalue == 0)
    {
        f.f = 5;
    }
    else if(fvalue == 1)
    {
        f.f = 0;
    }
    camera_set_f(f);
}

void app_setsspeed(int ssvalue)
{
    CHANGE_SS sspeed = {0};

    if(ssvalue == 0)
    {
        int sselect = 0;
    
        while(1)
        {
            printf("設定するシャッタースピードの値を選択してください 1.1/1秒 2.1/2秒 3.1/5秒 4.1/10秒");
            scanf("%d", &sselect);
                switch(sselect)
                {
                    case 1:
                        sspeed.ss = SET1;   /*1/1秒*/
                        break;
                    case 2:
                        sspeed.ss = SET2;   /*1/2秒*/
                        break;
                    case 3:
                        sspeed.ss = SET3;   /*1/5秒*/
                        break;
                    case 4:
                        sspeed.ss = SET4;   /*1/10秒*/
                        break;
                    default:
                        printf("入力された値は対応していません");
                        break;
                }

        }
    }
    else if (ssvalue == 1)
    {
        sspeed.ss = 0;
    }
    camera_set_sspeed(sspeed);
}

void app_setcolor_question()
{
    int colorvalue = 0;

    while(1)
    {
        printf("色彩設定メニュー 0.設定 1.初期化");
        scanf("%d", &colorvalue);
            switch(colorvalue)
            {
                case 0:
                case 1:
                    app_setcolor(colorvalue);
                    break;
                default:
                    printf("入力された値は対応していません");
                    break;
            }
        if(colorvalue == 0 || colorvalue == 1)
        {
            break;
        }
        else
        {
            continue;
        }
    }

}

void app_setsize_question()
{
    int sizevalue = 0;
    
    while (1)
    {
        printf("サイズ設定メニュー 0.設定 1.初期化");
        scanf("%d" , &sizevalue);
            switch(sizevalue)
            {
                case 0:
                case 1:
                    app_setsize(sizevalue);
                    break;
                default:
                    printf("入力された値は対応していません");
                    break;
            }
        if(sizevalue == 0 || sizevalue == 1)
        {
            break;
        }
        else
        {
            continue;
        }
    }
    
}

void app_setf_question()
{
    int fvalue = 0;
    
    while(1)
    {
        printf("F値設定メニュー 0.設定 1.初期化");
        scanf("%d" , &fvalue);
            switch(fvalue)
            {
                case 0:
                case 1:
                    app_setf(fvalue);
                    break;
                default:
                    printf("入力された値は対応していません");
                    break;
            }
        if(fvalue == 0 || fvalue == 1)
        {
            break;
        }
        else
        {
            continue;
        }
    }
}

void app_setsspeed_question()
{
    int ssvalue = 0;
    
    while(1)
    {
        printf("シャッタースピード設定メニュー 0.設定 1.初期化");
        scanf("%d" , &ssvalue);
            switch(ssvalue)
            {
                case 0:
                case 1:
                    app_setsspeed(ssvalue);
                    break;
                default:
                    printf("入力された値は対応していません");
                    break;
            }
        if(ssvalue == 0 || ssvalue == 1)
        {
            break;
        }
        else
        {
            continue;
        }
    }
}

void app_chenge_question()
{
    int chengevalue = 0;
    
    while(1)
    {
        printf("設定を実行しますか？ 0.はい 1.いいえ");
        scanf("%d", &chengevalue);
            switch(chengevalue)
            {
                case 0:
                    app_change_settings();
                    break;
                case 1:
                    /* このwhile文から抜ける*//*settingの入力に戻る*/
                    chenge_end =true;
                    break;
                default:
                    printf("入力された値は対応していません");
                    break; /*はい/いいえの入力に戻る*/
            }
        if(false != chenge_end)
        {
            break;
        }
        else
        {
            continue;
        }
    }

}

void app_end_question()
{
    int endvalue = 0;

    while(1)
    {
        printf("設定を終了しますか？ 0.はい 1.いいえ");
        scanf("%d",&endvalue);
        switch(endvalue)
        {
            case 0:
                end_judge = true;
                chenge_end = true;
                break;
            case 1:
                chenge_end = true; /*settingの入力に戻る*/
                break;
            default:
                printf("入力された値は対応していません");
                break;
        }
        if(false != chenge_end)
        {
            break;
        }
        else
        {
            continue;
        }
    }

}

void app_change_settings()
{
    camera_change_settings();
    /*設定変更用関数呼び出し*/
    camera_initialize();
    /*初期化用関数呼び出し*/
    app_end_question();
    /*設定終了用関数呼び出し*/
}

void main()
{
    int setting = 0;
    int ret = 0;
    bool end_judge = false;
    
    camera_initialize();
    while(1)
    {
        printf("メニューを選択してください。1.色彩設定 2.サイズ設定 3.F値設定 4.シャッタースピード設定 5.設定確定 6.設定終了");
        scanf("%d", &setting);
        switch(setting)
        {
            /*色彩設定*/
            case 1:
                app_setcolor_question();
                break;
            /*サイズ設定*/
            case 2:
                app_setsize_question();
                break;
            /*F値設定*/
            case 3:
                app_setf_question();
                break;
            /*シャッタースピード設定*/
            case 4:
                app_setsspeed_question();
                break;
            /*設定実行*/
            case 5:
                app_chenge_question();
                break;
            /*設定終了*/
            case 6:
                app_end_question();
                break;
            default:
                printf("入力された値は対応していません");
                break;
        }
        if(false != end_judge)
        {
            break;
        }
        else
        {
            continue;
        }
    }
}

   
