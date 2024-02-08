#include <stdint.h>

typedef enum{
    COLER = 0,   /* 色彩設定           */
    SIZE,        /* サイズ設定         */
    F,           /* F値設定            */
    SS,          /* シャッタースピード設定*/
    CHANGE_MAX   /* 変更可能機能最大数 */
}CHANGE_REQ;

/*シャッタースピード用*/
typedef enum{
    ONE = 0x00, 
    HARF,
    FIFTH,
    TENTH,
}SET_SSPEED;

/*シャッタースピードCase文用*/
typedef enum{
    INP_ONE = 1,
    INP_HARF,
    INP_FIFTH,
    INP_TENTH,
}CASE;

/*設定初期化用*/
typedef enum{
    SET = 1,
    INIT,
}SET_Q;

/*はい/いいえ用*/
typedef enum{
    YES = 1,
    NO,
}YN_Q;

/*設定選択用*/
typedef enum{
    INP_COLOR = 1,
    INP_SIZE,
    INP_F,
    INP_SS,
    INP_SET,
    INP_END,
}SET_SELECT;


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
void app_setcolor(int colorvalue);
void app_setsize(int sizevalue);
void app_setf(int fvalue);
void app_setsspeed(int ssvalue);
void app_setcolor_question();
void app_setsize_question();
void app_setf_question();
void app_setsspeed_question();
void app_chenge_question();
void app_end_question();
void app_chenge_settings();