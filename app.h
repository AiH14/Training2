#include <stdint.h>

typedef enum{
    COLER = 0,   /* 色彩設定           */
    SIZE,        /* サイズ設定         */
    F,           /* F値設定            */
    SS,          /* シャッタースピード設定*/
    CHANGE_MAX   /* 変更可能機能最大数 */
}CHANGE_REQ;

typedef enum{
    SET1 = 1, /*0x00*/
    SET2, /*0x01*/
    SET3,/*0x02*/
    SET4,/*0x03*/
}SET_SSPEED;

/* 色彩設定用構造体 */
typedef struct{
    uint32_t type;    /* タイプ設定 */ 
    uint32_t status;  /* 状態設定   */
}CHANGE_COLOR;

/* サイズ設定用構造体 */
typedef struct{
    uint32_t width;   /* 幅設定     */
    uint32_t length;  /* 高さ設定   */
}CHANGE_SIZE;

/* F値設定用構造体 */
typedef struct{
    uint32_t f;       /* F値設定    */
}CHANGE_F;

/* シャッタースピード設定用構造体*/
typedef struct{
    uint32_t ss; /*シャッタースピード設定*/
}CHANGE_SS;

/*関数宣言*/
void app_setsize(int sizevalue);
void app_setf(int fvalue);
void app_setsspeed(int ssvalue);
void app_set_setcolor_question();
void app_setsize_question();
void app_setf_question();
void app_setsspeed_question();
void app_chenge_question();
void app_end_question();
void app_chenge_settings();