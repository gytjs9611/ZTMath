#include "plusoperation.h"

void PlusOperation::createQuestion()
{
    Operation::createQuestion();

    int lv = this->m_level;
    std::cout<<lv<<std::endl;


    switch(lv){
    case 0:
        questionLvHigh();
        break;
    case 1:
        questionLvMid();
        break;
    case 2:
        questionLvLow();
        break;
    }


    for(int i = 1; i<m_num+1; i++){
        int temp = m_question[i].num1+m_question[i].num2;
        m_question[i].operatorSymbol = 1;
        m_question[i].answer = temp;
    }


}
void PlusOperation::questionLvHigh(){
    int i;
    int len = this->m_diff2;
    int range, num1;
    int num_up;
    int sum, temp;

    std::random_device rd;
    std::mt19937 gen(rd());

    if(len==1){
        for(i = 1; i<m_num+1; i++){
            num1 = this->m_question[i].num1;
            if(num1%10==0){
                range = 0;
            }
            else{
               range = 10 - num1%10;
            }
            std::uniform_int_distribution<int> dis(range, 9);
            this->m_question[i].num2 = dis(gen);
        }
    }
    else{ // len = 2, 3, 4

        for(int i = 1; i<m_num+1; i++){
            sum = 0;
            num1 = this->m_question[i].num1;
            std::uniform_int_distribution<int> dis(len-1, len); // num of 받아올림
            num_up = dis(gen);

            if(num_up==len){ // len
                for(int j = 0; j<len; j++){
                    temp = (num1 / (int)(pow(10, j)))%10;
                    if(temp==0){
                        range = 0;
                    }
                    else{
                        range = 10-temp;
                    }
                    std::uniform_int_distribution<int> dis(range, 9);
                    sum += dis(gen)*((int)(pow(10, j)));
                }
                this->m_question[i].num2 = sum;
                sum = 0;
            }
            else{ // len-1
                std::uniform_int_distribution<int> dis(0, len-1);
                int except_index = dis(gen);
                for(int j = 0; j<len; j++){
                    temp = (num1 / (int)(pow(10, j)))%10;
                    if(j!=except_index){ // 올림o
                        if(temp==0){
                            range = 0;
                        }
                        else{
                            range = 10-temp;
                        }
                        std::uniform_int_distribution<int> dis(range, 9);
                        temp = dis(gen);
                    }
                    else{ // 올림x
                        if(temp==0){
                            range = 9;
                        }
                        else{
                            range = 10-temp-1;
                        }
                        if(j==len-1){
                            if(range==0){
                                range++;
                            }
                            std::uniform_int_distribution<int> dis(1, range);
                            temp = dis(gen);
                        }
                        else{
                            std::uniform_int_distribution<int> dis(0, range);
                            temp = dis(gen);
                        }

                    }
                    sum += temp*((int)(pow(10, j)));

                }
                this->m_question[i].num2 = sum;
            }

        }
    }


}
void PlusOperation::questionLvMid(){
    int len = this->m_diff2;
    int sum = 0;
    int num1, range, temp;

    QPair<int, int> select_two_4[6] = {qMakePair(0,1), qMakePair(0,2), qMakePair(0,3), qMakePair(1,2), qMakePair(1,3), qMakePair(2,3)};
    QPair<int, int> select_two_3[3] = {qMakePair(0,1), qMakePair(0,2), qMakePair(1,2)};
    QPair<int, int> index;

    std::random_device rd;
    std::mt19937 gen(rd());

    if(len==3 || len==4){
        for(int i = 1; i<m_num+1; i++){
            num1 = this->m_question[i].num1;
            sum = 0;
            std::uniform_int_distribution<int> dis(len-2, len-1);
            int num_up = dis(gen);
            if(num_up==len-2){ // len-2
                printf("up %d : ", num_up);
                if(len==3){
                    std::uniform_int_distribution<int> dis(0, 2);
                    index = select_two_3[dis(gen)];
                }
                if(len==4){
                    std::uniform_int_distribution<int> dis(0, 5);
                    index = select_two_4[dis(gen)];
                }

                for(int j = 0; j<len; j++){
                    temp = (num1 / ((int)pow(10, j))) % 10;
                    if(j==index.first || j==index.second){ // 올림x
                        if(temp==0){
                            range = 9;
                        }
                        else{
                            range = 10-temp-1;
                        }
                        if(j==len-1){
                            if(range==0){
                                range++;
                            }
                            std::uniform_int_distribution<int> dis(1, range);
                            temp = dis(gen);
                        }
                        else{
                            std::uniform_int_distribution<int> dis(0, range);
                            temp = dis(gen);
                        }

                    }
                    else{ // 올림o
                        if(temp==0){
                            range = 0;
                        }
                        else{
                            range = 10-temp;
                        }
                        std::uniform_int_distribution<int> dis(range, 9);
                        temp = dis(gen);
                    }
                    sum += temp*((int)(pow(10, j)));
                }
            }
            else{ // len-1
                std::uniform_int_distribution<int> dis(0, len-1);
                int except_index = dis(gen);
                for(int j = 0; j<len; j++){
                    temp = (num1 / ((int)pow(10, j))) % 10;
                    if(j!=except_index){ // 올림o
                        if(temp==0){
                            range = 0;
                        }
                        else{
                            range = 10-temp;
                        }
                        std::uniform_int_distribution<int> dis(range, 9);
                        temp = dis(gen);
                    }
                    else{ // 올림x
                        if(temp==0){
                            range = 9;
                        }
                        else{
                            range = 10-temp-1;
                        }
                        if(j==len-1){
                            if(range==0){
                                range++;
                            }
                            std::uniform_int_distribution<int> dis(1, range);
                            temp = dis(gen);
                        }
                        else{
                            std::uniform_int_distribution<int> dis(0, range);
                            temp = dis(gen);
                        }
                    }
                    sum += temp*((int)(pow(10, j)));
                }
            }

            this->m_question[i].num2 = sum;
        }

    }
    else{ // len = 1, 2
        if(len==2){
            for(int i = 1; i<m_num+1; i++){
                num1 = this->m_question[i].num1;
                sum = 0;
                std::uniform_int_distribution<int> dis(0, 1);
                int except_index = dis(gen);

                for(int j = 0; j<len; j++){
                    temp = (num1 / ((int)pow(10, j))) % 10;
                    if(j!=except_index){ // 올림o
                        if(temp==0){
                            range = 0;
                        }
                        else{
                            range = 10-temp;
                        }
                        std::uniform_int_distribution<int> dis(range, 9);
                        temp = dis(gen);
                    }
                    else{ // 올림x
                        if(temp==0){
                            range = 9;
                        }
                        else{
                            range = 10-temp-1;
                        }
                        if(j==len-1){
                            if(range==0){
                                range++;
                            }
                            std::uniform_int_distribution<int> dis(1, range);
                            temp = dis(gen);
                        }
                        else{
                            std::uniform_int_distribution<int> dis(0, range);
                            temp = dis(gen);
                        }

                    }
                    sum += temp*((int)(pow(10, j)));
                }
                this->m_question[i].num2 = sum;
            }

        }
        if(len==1){
            for(int i = 1; i<m_num+1; i++){
                num1 = this->m_question[i].num1;
                temp = num1 % 10;
                sum = 0;
                std::uniform_int_distribution<int> dis(0, 1);
                int num_up = dis(gen);
                if(num_up==0){
                    if(temp==0){
                        range = 9;
                    }
                    else{
                        range = 10-temp-1;
                    }

                    if(range==0){
                        range++;
                    }
                    std::uniform_int_distribution<int> dis(1, range);
                    temp = dis(gen);

                }
                else{
                    if(temp==0){
                        range = 1;
                    }
                    else{
                        range = 10-temp;
                    }
                    std::uniform_int_distribution<int> dis(range, 9);
                    temp = dis(gen);
                }
                this->m_question[i].num2 = temp;
            }
        }

    }


}
void PlusOperation::questionLvLow(){
    int len = this->m_diff2;
    int sum, temp, num1, range;
    QPair<int, int> select_two_4[6] = {qMakePair(0,1), qMakePair(0,2), qMakePair(0,3), qMakePair(1,2), qMakePair(1,3), qMakePair(2,3)};
    QPair<int, int> index;

    std::random_device rd;
    std::mt19937 gen(rd());

    if(len==4){
        for(int i = 1; i<m_num+1; i++){
            sum = 0;
            num1 = this->m_question[i].num1;
            std::uniform_int_distribution<int> dis(1, 2);
            int num_up = dis(gen);
            if(num_up==1){ // 1개 올림
                std::uniform_int_distribution<int> dis(0, len-1);
                int selected_index = dis(gen);
                for(int j = 0; j<len; j++){
                    temp = (num1/(int)pow(10, j)) %10;
                    if(j==selected_index){ // 올림할 자리
                        if(temp==0){
                            range = 0;
                        }
                        else{
                            range = 10 - temp;
                        }
                        std::uniform_int_distribution<int> dis(range, 9);
                        temp = dis(gen);
                    }
                    else{ // 올림x
                        if(temp==0){
                            range = 9;
                        }
                        else{
                            range = 10-temp-1;
                        }
                        if(j==len-1){
                            if(range==0){
                                range++;
                            }
                            std::uniform_int_distribution<int> dis(1, range);
                            temp = dis(gen);
                        }
                        else{
                            std::uniform_int_distribution<int> dis(0, range);
                            temp = dis(gen);
                        }
                    }
                    sum += temp*(int)pow(10, j);
                }
                this->m_question[i].num2 = sum;
                printf("(%d) %d\n%d\n%d\n", num_up, selected_index+1, m_question[i].num1, m_question[i].num2);

            }
            else{ // 2개 올림
                std::uniform_int_distribution<int> dis(0, 5);
                index = select_two_4[dis(gen)];
                for(int j = 0; j<len; j++){
                    temp = (num1/(int)pow(10, j))%10;
                    if(j==index.first || j==index.second){ //올림x
                        if(temp==0){
                            range = 9;
                        }
                        else{
                            range = 10-temp-1;
                        }
                        if(j==len-1){
                            if(range==0){
                                range++;
                            }
                            std::uniform_int_distribution<int> dis(1, range);
                            temp = dis(gen);
                        }
                        else{
                            std::uniform_int_distribution<int> dis(0, range);
                            temp = dis(gen);
                        }
                    }
                    else{
                        if(temp==0){
                            range = 0;
                        }
                        else{
                            range = 10-temp;
                        }
                        std::uniform_int_distribution<int> dis(range, 9);
                        temp = dis(gen);
                    }
                    sum+=temp*(int)pow(10, j);
                }
                this->m_question[i].num2 = sum;
                printf("(%d) %d, %d\n%d\n%d\n", num_up, index.first+1, index.second+1, m_question[i].num1, m_question[i].num2);
            }
        }

    }
    if(len==3){ // len = 1, 2
        for(int i = 1; i<m_num+1; i++){
            num1 = this->m_question[i].num1;
            sum = 0;
            std::uniform_int_distribution<int> dis(0, len-1);
            int selected_index = dis(gen);
            for(int j = 0; j<len; j++){
                temp = (num1/(int)pow(10, j)) %10;
                if(j==selected_index){ // 올림할 자리
                    if(temp==0){
                        range = 0;
                    }
                    else{
                        range = 10 - temp;
                    }
                    std::uniform_int_distribution<int> dis(range, 9);
                    temp = dis(gen);
                }
                else{ // 올림x
                    if(temp==0){
                        range = 9;
                    }
                    else{
                        range = 10-temp-1;
                    }
                    if(j==len-1){
                        if(range==0){
                            range++;
                        }
                        std::uniform_int_distribution<int> dis(1, range);
                        temp = dis(gen);
                    }
                    else{
                        std::uniform_int_distribution<int> dis(0, range);
                        temp = dis(gen);
                    }
                }
                sum += temp*(int)pow(10, j);
            }
            this->m_question[i].num2 = sum;
        }

    }
    if(len==2){
        for(int i = 1; i<m_num+1; i++){
            num1 = this->m_question[i].num1;
            sum = 0;
            std::uniform_int_distribution<int> dis(0, 1);
            int num_up = dis(gen);
            printf("%d\n", num_up);
            if(num_up==0){ // 올림 0개
                for(int j = 0; j<len; j++){
                    temp = (num1/(int)pow(10, j))%10;
                    if(temp==0){
                        range = 9;
                    }
                    else{
                        range = 10-temp-1;
                    }
                    if(j==len-1){
                        if(range==0){
                            range++;
                        }
                        std::uniform_int_distribution<int> dis(1, range);
                        temp = dis(gen);
                    }
                    else{
                        std::uniform_int_distribution<int> dis(0, range);
                        temp = dis(gen);
                    }
                    printf("range %d temp %d\n", range, temp);
                    sum += temp*(int)pow(10, j);
                }
                this->m_question[i].num2 = sum;
                printf("%d\n%d\n", m_question[i].num1, m_question[i].num2);
            }
            else{ // 올림 1개
                std::uniform_int_distribution<int> dis(0, len-1);
                int selected_index = dis(gen);
                for(int j = 0; j<len; j++){
                    temp = (num1/(int)pow(10, j))%10;
                    if(j==selected_index){ // 올림할 자리
                        if(temp==0){
                            range = 0;
                        }
                        else{
                            range = 10 - temp;
                        }
                        std::uniform_int_distribution<int> dis(range, 9);
                        temp = dis(gen);
                    }
                    else{ // 올림x
                        if(temp==0){
                            range = 9;
                        }
                        else{
                            range = 10-temp-1;
                        }
                        if(j==len-1){
                            if(range==0){
                                range++;
                            }
                            std::uniform_int_distribution<int> dis(1, range);
                            temp = dis(gen);
                        }
                        else{
                            std::uniform_int_distribution<int> dis(0, range);
                            temp = dis(gen);
                        }
                    }
                    sum += temp*(int)pow(10, j);
                }
                this->m_question[i].num2 = sum;

                printf("%d\n%d\n", m_question[i].num1, m_question[i].num2);
            }


        }
    }
    if(len==1){
        for(int i = 1; i<m_num+1; i++){
            sum = 0;
            std::uniform_int_distribution<int> dis(0, 1);
            int num_up = dis(gen);
            if(num_up==0){
                std::uniform_int_distribution<int> dis(1, 9);
                temp = dis(gen);
            }
            else{
                num1 = this->m_question[i].num1;
                temp = num1 % 10;
                if(temp==0){
                    range = 1;
                }
                else{
                    range = 10-temp;
                }
                std::uniform_int_distribution<int> dis(range, 9);
                temp = dis(gen);
            }
            this->m_question[i].num2 = temp;
        }
    }

}

