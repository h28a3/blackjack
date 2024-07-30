#include"header.h"

int deck[13];

int main(void) {
    initialization();

    vector<vector<int>> card(2); //手札記録用変数

    for (int i = 0;i < 2;i++) {
        for (int j = 0;j < 2;j++)
            card[i].push_back(draw()); //初めにプレイヤー，ディーラーの両方に二枚配る
    }

    cout << "Player's card is "; //プレイヤーのカード出力
    for (int i = 0;i < card[1].size();i++)
        cout << card[0][i] << " ";
    cout << ".\n";

    int sum_player = sum_card(card[0]);

    while (true) {
        cout << "Do yuo wanna add a card?(y or n)"; //引く場合はy，引かない場合はnを入力
        char s;
        cin >> s;
        if (s == 'n')
            break;

        card[0].push_back(draw());

        cout << "Player's card is "; //プレイヤーのカード出力
        for (int i = 0;i < card[0].size();i++)
            cout << card[0][i] << " ";
        cout << ".\n";

        sum_player = sum_card(card[0]);
        if (sum_player > 21) { //21を超えたらバストしてプレイヤーの負け
            cout << "Player is busted.";
            return 0;
        }
    }

    cout << "Player's score is " << sum_player << ".\n" ;

    cout << "Dealer's card is "; //ディーラーのカード出力
    for (int i = 0;i < card[1].size();i++)
        cout << card[1][i] << " ";
    cout << ".\n";

    while (true) {
        int sum_dealer = sum_card(card[1]);
        if (sum_dealer <= 16) { //ディーラーはスコアが16以下のときはさらに引く
            card[1].push_back(draw());
            sum_dealer = sum_card(card[1]);
        }

        cout << "ディーラーのカードはDealer's card is "; //ディーラーのカード出力
        for (int i = 0;i < card[1].size();i++)
            cout << card[1][i] << " ";
        cout << ".\n";

        if (sum_dealer > 21) { //21を超えたらバストしてディーラーの負け
            cout << "Dealer's score is " << sum_dealer << "." << "\n";
            cout << "Dealer is busted.\nPlayer win.";
            return 0;
        }
        else if (sum_dealer >= 17) { //17を超えたら引くのをやめて勝敗判定
            cout << "Dealer's score is " << sum_dealer << "." << "\n";
            if (sum_dealer == sum_player)
                cout << "tie.";
            else if (sum_dealer > sum_player)
                cout << "Dealer wins.";
            else
                cout << "Player win.";
            return 0;
        }
    }
}
