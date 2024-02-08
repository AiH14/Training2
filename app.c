#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


#include "app.h"
#include "camerasetting.h"

static bool is_initialized = false;
static bool g_end_judge = false;

void app_setcolor(int colorvalue)
{
    CHANGE_COLOR color = {0};

    if(colorvalue == 1)
    {
        color.type = 1;
        color.status = 2;
    }
    else if(colorvalue == 2)
    {
        color.type = 0;
        color.status = 0;
    }
    camera_set_color(color);
}

void app_setsize(int sizevalue)
{
    CHANGE_SIZE size = {0};

    if(sizevalue == 1)
    {
        size.width = 3;
        size.length = 4;
    }
    else if(sizevalue == 2)
    {
        size.width = 0;
        size.length = 0;
    }
    camera_set_size(size);
}

void app_setf(int fvalue)
{
    CHANGE_F f = {0};

    if(fvalue == 1)
    {
        f.f = 5;
    }
    else if(fvalue == 2)
    {
        f.f = 0;
    }
    camera_set_f(f);
}

void app_setsspeed(int ssvalue)
{
    CHANGE_SS sspeed = {0};

    if(ssvalue == 1)
    {
        int sselect = 0;
    
        while(1)
        {
            printf("設定するシャッタースピードの値を選択してください 1.1/1秒 2.1/2秒 3.1/5秒 4.1/10秒");
            scanf("%d", &sselect);
                switch(sselect)
                {
                    case INP_ONE:
                        sspeed.ss = ONE;   /*1/1秒*/
                        break;
                    case INP_HARF:
                        sspeed.ss = HARF;   /*1/2秒*/
                        break;
                    case INP_FIFTH:
                        sspeed.ss = FIFTH;   /*1/5秒*/
                        break;
                    case INP_TENTH:
                        sspeed.ss = TENTH;   /*1/10秒*/
                        break;
                    default:
                        printf("入力された値は対応していません");
                        break;
                }

        }
    }
    else if (ssvalue == 2)
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
        printf("色彩設定メニュー 1.設定 2.初期化");
        scanf("%d", &colorvalue);
            switch(colorvalue)
            {
                case SET:
                case INIT:
                    app_setcolor(colorvalue);
                    break;
                default:
                    printf("入力された値は対応していません");
                    break;
            }
        if(colorvalue == 1 || colorvalue == 2)
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
        printf("サイズ設定メニュー 1.設定 2.初期化");
        scanf("%d" , &sizevalue);
            switch(sizevalue)
            {
                case SET:
                case INIT:
                    app_setsize(sizevalue);
                    break;
                default:
                    printf("入力された値は対応していません");
                    break;
            }
        if(sizevalue == 1 || sizevalue == 2)
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
        printf("F値設定メニュー 1.設定 2.初期化");
        scanf("%d" , &fvalue);
            switch(fvalue)
            {
                case SET:
                case INIT:
                    app_setf(fvalue);
                    break;
                default:
                    printf("入力された値は対応していません");
                    break;
            }
        if(fvalue == 1 || fvalue == 2)
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
        printf("シャッタースピード設定メニュー 1.設定 2.初期化");
        scanf("%d" , &ssvalue);
            switch(ssvalue)
            {
                case SET:
                case INIT:
                    app_setsspeed(ssvalue);
                    break;
                default:
                    printf("入力された値は対応していません");
                    break;
            }
        if(ssvalue == 1 || ssvalue == 2)
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
    bool chenge_end = false;
    
    while(1)
    {
        printf("設定を実行しますか？ 1.はい 2.いいえ");
        scanf("%d", &chengevalue);
            switch(chengevalue)
            {
                case YES:
                    app_change_settings();
                    chenge_end = true;
                    break;
                case NO:
                    /* このwhile文から抜ける*//*settingの入力に戻る*/
                    chenge_end = true;
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
    bool endflag = false;

    while(1)
    {
        printf("設定を終了しますか？ 1.はい 2.いいえ");
        scanf("%d",&endvalue);
        switch(endvalue)
        {
            case YES:
                g_end_judge = true;
                endflag = true;
                break;
            case NO:
                endflag = true; /*settingの入力に戻る*/
                break;
            default:
                printf("入力された値は対応していません");
                break;
        }
        if(false != endflag)
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
            case INP_COLOR:
                app_setcolor_question();
                break;
            /*サイズ設定*/
            case INP_SIZE:
                app_setsize_question();
                break;
            /*F値設定*/
            case INP_F:
                app_setf_question();
                break;
            /*シャッタースピード設定*/
            case INP_SS:
                app_setsspeed_question();
                break;
            /*設定実行*/
            case INP_SET:
                app_chenge_question();
                break;
            /*設定終了*/
            case INP_END:
                app_end_question();
                break;
            default:
                printf("入力された値は対応していません");
                break;
        }
        if(false != g_end_judge)
        {
            break;
        }
        else
        {
            continue;
        }
    }
}

   
