#include"header.h"

void initialization() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand((unsigned int)time(NULL));
    for (int i = 0;i < 13;i++)
        deck[i] = 4; //�R�D����
}

int sum_card(vector<int> a) { //��D�̍��v���v�Z����D
    int sum = 0;
    for (int i = 0;i < a.size();i++) {
        if (a[i] > 10) sum += 10; //11~13��10�Ƃ��Đ�������
        else sum += a[i];
    }
    if (find(a.begin(), a.end(), 1) != a.end() && sum <= 11)
        sum += 10; //1��1�܂���11�̓s���̗ǂ����Ő�������
    return sum;
}

int draw() { //�J�[�h�������֐�
    int r;
    while (true) {
        r = rand() % 13 + 1; //��������
        if (deck[r] > 0) { //�R�D�Ɋ܂܂��J�[�h�̂ݏ���
            deck[r]--;
            break;
        }
    }
    return r;
}
