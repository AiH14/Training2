#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int playerHand;
    int computerHand;
    
    printf("じゃんけんを繰り返し行います。\n");
    
    while (1) {
        printf("自分の手を入力してください(1: グー,pro 2: チョキ, 3: パー): ");
        scanf("%d", &playerHand);
        
        srand(time(NULL));
        computerHand = rand() % 3 + 1;
        
        if (playerHand == computerHand) {
            printf("引き分けです。\n");
        } else if ((playerHand == 1 && computerHand == 2) || (playerHand == 2 && computerHand == 3) || (playerHand == 3 && computerHand == 1)) {
            printf("プレイヤーの勝ちです！\n");
        } else {
            printf("コンピュータの勝ちです。\n");
        }
        
        printf("もう一度じゃんけんを行いますか？(1: はい, 2: いいえ): ");
        int continueFlag;
        scanf("%d", &continueFlag);
        
        if (continueFlag != 1) {
            break;
        }
    }
    
    printf("じゃんけんを終了します。\n");
    
    return 0;
}


