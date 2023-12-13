#include app.h
#include <stdint.h>

typedef struct {
    bool is_onoff[CHANGE_MAX];
    APPEND_COLOR  color;
    APPEND_SIZE   size;
    APPEND_F      f;
}CameraCtrl;

/* 色彩設定用構造体 */
typedef struct{
    uint32_t type;    /* タイプ設定 */
    uint32_t status;  /* 状態設定   */
}APPEND_COLOR;

/* サイズ設定用構造体 */
typedef struct{
    uint32_t width;   /* 幅設定     */
    uint32_t length;  /* 高さ設定   */
}APPEND_SIZE;

/* F値設定用構造体 */
typedef struct{
    uint32_t f;       /* F値設定    */
    uint32_t sspeed;  /* シャッタースピード設定 */
}APPEND_F;

/* 関数宣言 */
void camera_initialize();
void camera_set_color(CHANGE_COLOR color);
void camera_set_size(CHANGE_SIZE size);
void camera_set_f(CHANGE_F f);
int camera_append_setting(CHANGE_REQ req, bool onoff);
int camera_change_settings();

