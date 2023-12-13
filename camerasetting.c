#include <stdio.h>
#include <stdint.h>

#include app.h
#include camerasetting.h

static CameraCtrl     g_CmrCtrl = { 0 };

void camera_initialize()
{
    memset(&g_CmrCtrl.is_onoff, 0, sizeof(g_CmrCtrl.is_onoff));
    memset(&g_CmrCtrl.color, 0, sizeof(g_CmrCtrl.color));
    memset(&g_CmrCtrl.size, 0, sizeof(g_CmrCtrl.size));
    memset(&g_CmrCtrl.f, 0, sizeof(g_CmrCtrl.f));
}

void camera_set_color(CHANGE_COLOR color)
{
    g_CmrCtrl.color.type = color.type;
    g_CmrCtrl.color.status = color.status;
}

void camera_set_size(CHANGE_SIZE size)
{
    g_CmrCtrl.size.width = size.width;
    g_CmrCtrl.size.length = size.length;
}

void camera_set_f(CHANGE_F f)
{
    g_CmrCtrl.f.f = f.f;
    g_CmrCtrl.f.sspeed = f.sspeed;
}

int camera_append_setting(CHANGE_REQ req, bool onoff)
{
    int ret = 0;
    if (req >= CHANGE_MAX)
    {
        ret = 1;
    }
    else
    {
        g_CmrCtrl.is_onoff[req] = onoff;
    }
    
    return(ret);
}

int camera_change_settings()
{
    int ret = 0;
    for (i = 0; i < CHANGE_MAX; i++)
    {
        if(ret == 0)
        {
            if (false != g_CmrCtrl.is_onoff[i])
            {
                switch (i)
                {
                    /* 色彩設定 */
                    case COLER:
                        ret = camera_change_color();
                        break;
                    /* サイズ設定 */
                    case SIZE;
                        ret = camera_change_size();
                        break;
                    /* F値設定 */
                    case F;
                        ret = camera_change_f();
                        break;
                    default:
                        ret = 1;
                        break;
                }
            }
            else
            { /* Do Nothing. */ } 
        }
        else
        {
            printf("Camera設定に失敗しました。\n");
            return(ret);
        }
    }
    return(ret);
}

int camera_change_color()
{
    int ret = 0;
    if(g_CmrCtrl.color.type != 0 && g_CmrCtrl.color.status != 0)
    {
        printf("色彩設定完了しました。\n");
    }
    else
    {
        printf("色彩設定失敗しました。\n");
        ret = 1;
    }
    return(ret);
}

int camera_change_size()
{
    int ret = 0;
    if(g_CmrCtrl.size.width != 0 && g_CmrCtrl.size.length != 0)
    {
        printf("サイズ設定完了しました。\n");
    }
    else
    {
        printf("サイズ設定失敗しました。\n");
        ret = 1;
    }
    return(ret);
}

int camera_change_f()
{
    int ret = 0;
    if(g_CmrCtrl.f.f != 0 && g_CmrCtrl.size.sspeed != 0)
    {
        printf("F値設定完了しました。\n");
    }
    else
    {
        printf("F値設定失敗しました。\n");
        ret = 1;
    }
    return(ret);
}