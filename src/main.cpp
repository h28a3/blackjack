#include"header.h"

int deck[13];

int main(void) {
    int coin = initialization();
    int flag = 0;
    
    int count = 0;
    int sum_player = 0;

    while (coin > 0) {
        vector<vector<int>> card(2); //手札記録用変数
        count++;
        cout << "\n"<< count << "回目の勝負を開始します．\n";

        int bet;
        bet = betting(coin);
        for (int i = 0;i < 2;i++) {
            for (int j = 0;j < 2;j++)
                card[i].push_back(draw()); //初めにプレイヤー，ディーラーの両方に二枚配る
        }

        cout << "\nプレイヤー"; //プレイヤーのカード出力
        show_card(card[0]);
        sum_player = sum_card(card[0]);

        while (true) {
            cout << "もう一枚引きますか？(y or n)"; //引く場合はy，引かない場合はnを入力
            char s;
            cin >> s;
            if (s == 'n')
                break;
            card[0].push_back(draw());

            cout << "\nプレイヤー"; //プレイヤーのカード出力
            show_card(card[0]);

            sum_player = sum_card(card[0]);
            if (sum_player > 21) { //21を超えたらバストしてプレイヤーの負け
                cout << "バストしました．\n";
                coin -= bet;
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            continue;;

        cout << "あなたのスコアは" << sum_player << "です．\n\n";

        cout << "ディーラー"; //ディーラーのカード出力
        show_card(card[1]);

        while (true) {
            int sum_dealer = sum_card(card[1]);
            if (sum_dealer <= 16) { //ディーラーはスコアが16以下のときはさらに引く
                card[1].push_back(draw());
                sum_dealer = sum_card(card[1]);
            }
            cout << "ディーラー"; //ディーラーのカード出力
            show_card(card[1]);

            if (sum_dealer > 21) { //21を超えたらバストしてディーラーの負け
                cout << "ディーラーのスコアは" << sum_dealer << "です．" << "\n";
                cout << "ディーラーがバスト\nプレイヤーの勝利";
                coin += bet;
                break;
            }
            else if (sum_dealer >= 17) { //17を超えたら引くのをやめて勝敗判定
                cout << "ディーラーのスコアは" << sum_dealer << "です．" << "\n";
                if (sum_dealer == sum_player)
                    cout << "ドロー\n";
                else if (sum_dealer > sum_player) {
                    cout << "ディーラーの勝利\n";
                    coin -= bet;
                }
                else {
                    cout << "プレイヤーの勝利\n";
                    coin += bet;
                }
                break;
            }
        }
    }
    cout << "所持金がなくなりました\n";
    return 0;
}
