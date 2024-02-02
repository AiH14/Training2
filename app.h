#include <stdint.h>

typedef enum{
    COLER = 0,   /* 色彩設定           */
    SIZE,        /* サイズ設定         */
    F,           /* F値設定            */
    SS,          /* シャッタースピード設定*/
    CHANGE_MAX   /* 変更可能機能最大数 */
}CHANGE_REQ;

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