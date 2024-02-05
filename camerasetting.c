#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "app.h"
#include "camerasetting.h"

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
    g_CmrCtrl.is_onoff[0] = 1;
}

void camera_set_size(CHANGE_SIZE size)
{
    g_CmrCtrl.size.width = size.width;
    g_CmrCtrl.size.length = size.length;
    g_CmrCtrl.is_onoff[1] = 1;
}

void camera_set_f(CHANGE_F f)
{
    g_CmrCtrl.f.f = f.f;
    g_CmrCtrl.is_onoff[2] = 1;
}

void camera_set_sspeed(CHANGE_SS sspeed)
{
    g_CmrCtrl.ss.sspeed = sspeed.ss;
    g_CmrCtrl.is_onoff[3] = 1;
}

void camera_change_settings()
{
    int i;
    for (i = 0; i < CHANGE_MAX; i++)
    {
        if (false != g_CmrCtrl.is_onoff[i])
        {
            switch (i)
            {
                /* 色彩設定 */
                case COLER:
                    camera_change_color();
                    break;
                /* サイズ設定 */
                case SIZE:
                    camera_change_size();
                    break;
                /* F値設定 */
                case F:
                    camera_change_f();
                    break;
                case SS:
                    camera_chenge_sspeed();
                    break;
            }
        }
        else
        { /* Do Nothing. */ } 
    }
    
}

void camera_change_color()
{
    printf("色彩設定完了しました。\n");
}

void camera_change_size()
{
    printf("サイズ設定完了しました。\n");
}

void camera_change_f()
{
    printf("F値設定完了しました。\n");
}

void camera_chenge_sspeed()
{
    printf("シャッタースピード設定完了しました。\n");
}