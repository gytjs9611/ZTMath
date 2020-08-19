#include "minusoperation.h"

void MinusOperation::createQuestion()
{
    int from, to;

    Operation::createQuestion();

    std::random_device rd;
    std::mt19937 gen(rd());

    from = 2*(int)(pow(10, this->m_diff1-1));
    to = (int)(pow(10, this->m_diff1)-1);
    std::uniform_int_distribution<int> dis(from, to);

    for(int i = 1; i<m_num+1; i++){
        this->m_question[i].num1 = dis(gen);
    }

    int lv = this->m_level;

    srand(time(NULL));

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
        int temp = m_question[i].num1 - m_question[i].num2;
        m_question[i].operatorSymbol = 2;
        m_question[i].answer = temp;
    }
}
void MinusOperation::questionLvHigh(){
    int len1, len2;
    int num1, temp, range, down_num, sum;
    int except_index, selected_index;

    len1 = this->m_diff1;
    len2 = this->m_diff2;

    std::random_device rd;
    std::mt19937 gen(rd());

    if(len1==len2){
        if(len2==3 || len2==4){
            for(int i = 1; i<m_num+1; i++){
                sum = 0;
                num1 = this->m_question[i].num1;
                std::uniform_int_distribution<int> dis(len2-2, len2-1);
                down_num = dis(gen);
                if(down_num==len2-1){
                    for(int j = 0; j<len2; j++){
                        temp = (num1/(int)pow(10, j))%10;
                        if(j==len2-1){
                            std::uniform_int_distribution<int> dis(1, temp-1);
                            temp = dis(gen);
                        }
                        else{
                            if(temp==9){
                                range = 0;
                            }
                            else{
                                range = temp+1;
                            }
                            std::uniform_int_distribution<int> dis(range, 9);
                            temp = dis(gen);
                        }
                        sum += temp*(int)pow(10, j);
                    }
                    this->m_question[i].num2 = sum;

                }
                else{ // len2-2
                    std::uniform_int_distribution<int> dis(0, len2-2);
                    except_index = dis(gen);
                    for(int j = 0; j<len2; j++){
                        temp = (num1/(int)pow(10, j))%10;
                        if(j==len2-1){
                            std::uniform_int_distribution<int> dis(1, temp-1);
                            temp = dis(gen);
                        }
                        else if(j==except_index){
                            std::uniform_int_distribution<int> dis(0, temp);
                            temp = dis(gen);
                        }
                        else{
                            if(temp==9){
                                range = 0;
                            }
                            else{
                                range = temp+1;
                            }
                            std::uniform_int_distribution<int> dis(range, 9);
                            temp = dis(gen);
                        }
                        sum += temp*(int)pow(10, j);
                    }
                    this->m_question[i].num2 = sum;
                }
            }
        }

        if(len2==2){
            for(int i = 1; i<m_num+1; i++){
                num1 = this->m_question[i].num1;
                sum = 0;

                temp = (num1/(int)pow(10, 1))%10;
                std::uniform_int_distribution<int> dis(1, temp-1);
                temp = dis(gen);
                sum += temp*(int)pow(10, 1);

                temp = (num1/(int)pow(10, 0))%10;
                if(temp==9){
                    range = 0;
                }
                else{
                    range = temp+1;
                }
                std::uniform_int_distribution<int> dis2(range, 9);
                temp = dis2(gen);
                sum += temp*(int)pow(10, 0);
                this->m_question[i].num2 = sum;
            }
        }
        if(len2==1){
            for(int i = 1; i<m_num+1; i++){
                std::uniform_int_distribution<int> dis(1, 9);
                this->m_question[i].num1 = dis(gen);
                num1 = this->m_question[i].num1;
                std::uniform_int_distribution<int> dis2(1, num1);
                this->m_question[i].num2 = dis2(gen);
            }
        }
    }


    else{ // len1!=len2
        if(len2==3){
            for(int i = 1; i<m_num+1; i++){
                sum = 0;
                num1 = this->m_question[i].num1;
                std::uniform_int_distribution<int> dis(2, 3);
                down_num = dis(gen);
                if(down_num==2){
                    std::uniform_int_distribution<int> dis(0, len2-1);
                    except_index = dis(gen);
                    for(int j = 0; j<len2; j++){
                        temp = (num1/ (int)pow(10, j))%10;
                        range = 0;
                        if(j==len2-1){
                            range = 1;
                        }
                        if(j==except_index){
                            if(j==len2-1 && temp==0){
                                temp = 9;
                            }
                            std::uniform_int_distribution<int> dis(range, temp);
                            temp = dis(gen);
                        }
                        else{
                            if(temp==9){
                                if(j==len2-1){
                                    range = 1;
                                }
                                else{
                                    range = 0;
                                }
                            }
                            else{
                                range = temp+1;
                            }
                            std::uniform_int_distribution<int> dis(range, 9);
                            temp = dis(gen);
                        }
                        sum+=temp*(int)pow(10, j);
                    }
                }
                if(down_num==3){
                    for(int j = 0; j<len2; j++){
                        temp = (num1/ (int)pow(10, j))%10;
                        if(temp==9){
                            if(j==len2-1){
                                range = 1;
                            }
                            else{
                                range = 0;
                            }
                        }
                        else{
                            range = temp+1;
                        }
                        std::uniform_int_distribution<int> dis(range, 9);
                        temp = dis(gen);
                        sum += temp*(int)pow(10, j);
                    }
                }
                this->m_question[i].num2 = sum;
                printf("down_num %d, num1 %d, num2 %d\n", down_num, num1, sum);
            }
        }
        if(len2==2){
            for(int i = 1; i<m_num+1; i++){
                sum = 0;
                num1 = this->m_question[i].num1;
                std::uniform_int_distribution<int> dis(1, 2);
                down_num = dis(gen);
                if(down_num==1){
                    std::uniform_int_distribution<int> dis(0, 1);
                    except_index = dis(gen);
                    for(int j = 0; j<len2; j++){
                        temp = (num1/(int)pow(10, j))%10;
                        range = 0;
                        if(j==len2-1){
                            range = 1;
                        }
                        if(j==except_index){
                            if(j==len2-1 && temp==0){
                                temp = 9;
                            }
                            std::uniform_int_distribution<int> dis(range, temp);
                            temp = dis(gen);
                        }
                        else{
                            if(temp==9){
                                if(j==len2-1){
                                    range = 1;
                                }
                                else{
                                    range = 0;
                                }
                            }
                            else{
                                range = temp+1;
                            }
                            std::uniform_int_distribution<int> dis(range, 9);
                            temp = dis(gen);
                        }
                        sum += temp*(int)pow(10, j);
                    }
                }
                if(down_num==2){
                    for(int j = 0; j<len2; j++){
                        temp = (num1/ (int)pow(10, j))%10;
                        if(temp==9){
                            if(j==len2-1){
                                range = 1;
                            }
                            else{
                                range = 0;
                            }
                        }
                        else{
                            range = temp+1;
                        }
                        std::uniform_int_distribution<int> dis(range, 9);
                        temp = dis(gen);
                        sum += temp*(int)pow(10, j);
                    }
                }
                this->m_question[i].num2 = sum;
            }
        }
        if(len2==1){
            for(int i = 1; i<m_num+1; i++){
                sum = 0;
                num1 = this->m_question[i].num1;
                std::uniform_int_distribution<int> dis(0, 1);
                down_num = dis(gen);
                temp = (num1/ (int)pow(10, 0))%10;
                if(down_num==0){
                    if(temp==0){
                        std::uniform_int_distribution<int> dis(1, 9);
                        temp = dis(gen);
                    }
                    else{
                        std::uniform_int_distribution<int> dis(1, temp);
                        temp = dis(gen);
                    }

                    sum = temp;
                }
                if(down_num==1){
                    if(temp==9){
                        range = 1;
                    }
                    else{
                        range = temp+1;
                    }
                    std::uniform_int_distribution<int> dis(range, 9);
                    sum = dis(gen);
                }
                this->m_question[i].num2 = sum;
            }
        }
    }

}
void MinusOperation::questionLvMid(){
    int len1, len2;
    int num1, temp, range, down_num, sum;
    int except_index, selected_index;

    len1 = this->m_diff1;
    len2 = this->m_diff2;

    std::random_device rd;
    std::mt19937 gen(rd());

    if(len1==len2){
        if(len2==4){
            std::uniform_int_distribution<int> dis(1, 2);
            down_num = dis(gen);
            for(int i = 1; i<m_num+1; i++){
                num1 = this->m_question[i].num1;

                temp = (num1/(int)pow(10, len2-1))%10;
                std::uniform_int_distribution<int> dis(1, temp-1);
                temp = dis(gen);
                sum = temp*(int)pow(10, len2-1);

                std::uniform_int_distribution<int> dis2(1, 2);
                down_num = dis(gen);

                if(down_num==1){
                    std::uniform_int_distribution<int> dis(0, len2-2);
                    selected_index = dis(gen);
                    for(int j = 0; j<len2-1; j++){
                        temp = (num1/(int)pow(10, j))%10;
                        if(selected_index){
                            if(temp==9){
                                range = 0;
                            }
                            else{
                                range = temp+1;
                            }
                            std::uniform_int_distribution<int> dis(range, 9);
                            temp = dis(gen);
                        }
                        else{
                            if(temp==0){
                                std::uniform_int_distribution<int> dis(0, 9);
                                temp = dis(gen);
                            }
                            else{
                                std::uniform_int_distribution<int> dis(0, temp-1);
                                temp = dis(gen);
                            }
                        }
                        sum += temp*(int)pow(10, j);
                    }
                }

                if(down_num==2){
                    std::uniform_int_distribution<int> dis(0, len2-2);
                    except_index = dis(gen);
                    for(int j = 0; j<len2-1; j++){
                        temp = (num1/(int)pow(10, j))%10;

                        if(except_index){
                            if(temp==0){
                                std::uniform_int_distribution<int> dis(0, 9);
                                temp = dis(gen);
                            }
                            else{
                                std::uniform_int_distribution<int> dis(0, temp-1);
                                temp = dis(gen);
                            }
                        }
                        else{
                            if(temp==9){
                                range = 0;
                            }
                            else{
                                range = temp+1;
                            }
                            std::uniform_int_distribution<int> dis(range, 9);
                            temp = dis(gen);
                        }
                        sum += temp* (int)pow(10, j);
                    }
                }

                this->m_question[i].num2 = sum;
            }
        }

        if(len2==3){
            for(int i = 1; i<m_num+1; i++){
                num1 = this->m_question[i].num1;

                temp = (num1/(int)pow(10, len2-1))%10;
                std::uniform_int_distribution<int> dis(1, temp-1);
                temp = dis(gen);
                sum = temp*(int)pow(10, len2-1);

                std::uniform_int_distribution<int> dis2(0, len2-2);
                selected_index = dis2(gen);

                for(int j = 0; j<len2-1; j++){
                    temp = (num1/(int)pow(10, j))%10;
                    if(selected_index){
                        if(temp==9){
                            range = 0;
                        }
                        else{
                            range = temp+1;
                        }
                        std::uniform_int_distribution<int> dis(range, 9);
                        temp = dis(gen);
                    }
                    else{
                        if(temp==0){
                            std::uniform_int_distribution<int> dis(0, 9);
                            temp = dis(gen);
                        }
                        else{
                            std::uniform_int_distribution<int> dis(0, temp-1);
                            temp = dis(gen);
                        }
                    }
                    sum += temp*(int)pow(10, j);
                }
                this->m_question[i].num2 = sum;
            }

        }

        if(len2==2){
            for(int i = 1; i<m_num+1; i++){
                num1 = this->m_question[i].num1;
                sum = 0;

                temp = (num1/(int)pow(10, len2-1))%10;
                std::uniform_int_distribution<int> dis(1, temp-1);
                temp = dis(gen);
                sum = temp*(int)pow(10, len2-1);

                std::uniform_int_distribution<int> dis2(0, 1);
                down_num = dis2(gen);

                temp = (num1/(int)pow(10, 0))%10;
                if(down_num==0){
                    if(temp==0){
                        std::uniform_int_distribution<int> dis(0, 9);
                        temp = dis(gen);
                    }
                    else{
                        std::uniform_int_distribution<int> dis(0, temp-1);
                        temp = dis(gen);
                    }
                }
                if(down_num==1){
                    if(temp==9){
                        range = 0;
                    }
                    else{
                        range = temp+1;
                    }
                    std::uniform_int_distribution<int> dis(range, 9);
                    temp = dis(gen);
                }

                sum += temp;
                this->m_question[i].num2 = sum;
            }
        }

        if(len2==1){
            for(int i = 1; i<m_num+1; i++){
                num1 = this->m_question[i].num1;
                std::uniform_int_distribution<int> dis(1, num1-1);
                temp = dis(gen);
                this->m_question[i].num2 = temp;
            }
        }
    }


    else{ // len1!=len2
        if(len2==3){
            for(int i = 1; i<m_num+1; i++){
                sum = 0;
                num1 = this->m_question[i].num1;
                std::uniform_int_distribution<int> dis(1, 2);
                down_num = dis(gen);
                if(down_num==1){
                    std::uniform_int_distribution<int> dis(0, len2-1);
                    selected_index = dis(gen);
                    for(int j = 0; j<len2; j++){
                        temp = (num1/(int)pow(10, j))%10;
                        if(j==selected_index){
                            if(temp==9){
                                range = 0;
                                if(j==len2-1){
                                    range = 1;
                                }
                            }
                            else{
                                range = temp+1;
                            }
                            std::uniform_int_distribution<int> dis(range, 9);
                            temp = dis(gen);
                        }
                        else{
                            range = 0;
                            if(j==len2-1){
                                range = 1;
                            }
                            if(temp==0){
                                std::uniform_int_distribution<int> dis(range, 9);
                                temp = dis(gen);
                            }
                            else{
                                std::uniform_int_distribution<int> dis(range, temp);
                                temp = dis(gen);
                            }
                        }
                        sum += temp* (int)pow(10, j);
                    }
                    this->m_question[i].num2 = sum;
                }

                if(down_num==2){
                    std::uniform_int_distribution<int> dis(0, len2-1);
                    except_index = dis(gen);
                    for(int j = 0; j<len2; j++){
                        temp = (num1/(int)pow(10, j))%10;
                        if(j==except_index){
                            range = 0;
                            if(j==len2-1){
                                range = 1;
                            }
                            if(temp==0){
                                std::uniform_int_distribution<int> dis(range, 9);
                                temp = dis(gen);
                            }
                            else{
                                std::uniform_int_distribution<int> dis(range, temp);
                                temp = dis(gen);
                            }
                        }
                        else{
                            if(temp==9){
                                range = 0;
                                if(j==len2-1){
                                    range = 1;
                                }
                            }
                            else{
                                range = temp+1;
                            }
                            std::uniform_int_distribution<int> dis(range, 9);
                            temp = dis(gen);
                        }
                        sum += temp*(int)pow(10, j);
                    }
                }

                this->m_question[i].num2 = sum;
            }
        }

        if(len2==2){
            for(int i =1; i<m_num+1; i++){
                sum = 0;
                num1 = this->m_question[i].num1;

                std::uniform_int_distribution<int> dis(0, len2-1);
                selected_index = dis(gen);

                for(int j = 0; j<len2; j++){
                    temp = (num1/(int)pow(10, j))%10;
                    if(j==selected_index){
                        if(temp==9){
                            range = 0;
                            if(j==len2-1){
                                range = 1;
                            }
                        }
                        else{
                            range = temp+1;
                        }
                        std::uniform_int_distribution<int> dis(range, 9);
                        temp = dis(gen);
                    }
                    else{
                        range = 0;
                        if(j==len2-1){
                            range = 1;
                        }
                        if(temp==0){
                            std::uniform_int_distribution<int> dis(range, 9);
                            temp = dis(gen);
                        }
                        else{
                            std::uniform_int_distribution<int> dis(range, temp);
                            temp = dis(gen);
                        }
                    }
                    sum += temp* (int)pow(10, j);
                }
                this->m_question[i].num2 = sum;
            }
        }

        if(len2==1){
            for(int i = 1; i<m_num+1; i++){
                num1 = this->m_question[i].num1;
                std::uniform_int_distribution<int> dis(0, 1);
                down_num = dis(gen);
                temp = num1 % 10;
                if(down_num==1){
                    temp = num1 % 10;
                    if(temp==9){
                        range = 1;
                    }
                    else{
                        range = temp+1;
                    }
                    std::uniform_int_distribution<int> dis(range, 9);
                    sum = dis(gen);
                }

                if(down_num==0){
                    if(temp==0){
                        std::uniform_int_distribution<int> dis(1, 9);
                        sum = dis(gen);
                    }
                    else{
                        std::uniform_int_distribution<int> dis(1, temp);
                        sum = dis(gen);
                    }

                }
                this->m_question[i].num2 = sum;
            }
        }
    }
}
void MinusOperation::questionLvLow(){
    int len1, len2;
    int num1, temp, range, down_num, sum;
    int except_index, selected_index;

    len1 = this->m_diff1;
    len2 = this->m_diff2;

    std::random_device rd;
    std::mt19937 gen(rd());

    if(len1==len2){
        if(len2!=1){ // len2 = 2,3,4
            for(int i = 1; i<m_num+1; i++){
                sum = 0;
                num1 = this->m_question[i].num1;

                temp = (num1/(int)pow(10, len2-1))%10;
                std::uniform_int_distribution<int> dis(1, temp-1);
                temp = dis(gen);
                sum = temp*(int)pow(10, len2-1);

                std::uniform_int_distribution<int> dis2(0, 1);
                down_num = dis2(gen);

                if(down_num==0){
                    for(int j = 0; j<len2-1; j++){
                        temp = (num1/(int)pow(10, j))%10;
                        if(temp==0){
                            std::uniform_int_distribution<int> dis(0, 9);
                            temp = dis(gen);
                        }
                        else{
                            std::uniform_int_distribution<int> dis(0, temp-1);
                            temp = dis(gen);
                        }
                        sum += temp* (int)pow(10, j);
                    }
                }

                if(down_num==1){
                    std::uniform_int_distribution<int> dis(0, len2-2);
                    selected_index = dis(gen);
                    for(int j = 0; j<len2-1; j++){
                        temp = (num1/(int)pow(10, j))%10;
                        if(selected_index){
                            if(temp==9){
                                range = 0;
                            }
                            else{
                                range = temp+1;
                            }
                            std::uniform_int_distribution<int> dis(range, 9);
                            temp = dis(gen);
                        }
                        else{
                            if(temp==0){
                                std::uniform_int_distribution<int> dis(0, 9);
                                temp = dis(gen);
                            }
                            else{
                                std::uniform_int_distribution<int> dis(0, temp-1);
                                temp = dis(gen);
                            }
                        }
                        sum += temp*(int)pow(10, j);
                    }
                }
                this->m_question[i].num2 = sum;
            }
        }

        if(len2 == 1){
            for(int i = 1; i<m_num+1; i++){
                num1 = this->m_question[i].num1;

                std::uniform_int_distribution<int> dis(1, num1);
                sum = dis(gen);
                this->m_question[i].num2 = sum;
            }
        }

    }

    else{ // len!=len2
        if(len2!=1){
            for(int i = 1; i<m_num+1; i++){
                sum =0;
                num1 = this->m_question[i].num1;

                std::uniform_int_distribution<int> dis(0, 1);
                down_num = dis(gen);

                if(down_num==0){
                    for(int j = 0; j<len2; j++){
                        temp = (num1/(int)pow(10,j))%10;
                        range = 0;
                        if(j==len2-1){
                            range = 1;
                        }
                        if(temp==0){
                            std::uniform_int_distribution<int> dis(range, 9);
                            temp = dis(gen);
                        }
                        else{
                            std::uniform_int_distribution<int> dis(range, temp);
                            temp = dis(gen);
                        }
                        sum += temp*(int)pow(10, j);
                    }
                }

                if(down_num==1){
                    std::uniform_int_distribution<int> dis(0, 1);
                    selected_index = dis(gen);
                    for(int j=0; j<len2; j++){
                        temp = (num1/(int)pow(10, j))%10;
                        if(j==selected_index){
                            if(temp==9){
                               if(j==len2-1){
                                   range = 1;
                               }
                               else{
                                   range = 0;
                               }
                            }
                            else{
                                range = temp+1;
                            }
                            std::uniform_int_distribution<int> dis(range, 9);
                            temp = dis(gen);
                        }
                        else{
                            range = 0;
                            if(j==len2-1){
                                range = 1;
                            }
                            if(temp==0){
                                std::uniform_int_distribution<int> dis(range, 9);
                                temp = dis(gen);
                            }
                            else{
                                std::uniform_int_distribution<int> dis(range, temp);
                                temp = dis(gen);
                            }
                        }
                        sum += temp*(int)pow(10, j);
                    }
                }

                this->m_question[i].num2 = sum;
            }
        }
        if(len2==1){
            for(int i =1; i<m_num+1; i++){
                num1 = this->m_question[i].num1;
                temp = num1 % 10;
                if(temp==0){
                    range = 9;
                }
                else{
                    range = temp;
                }
                std::uniform_int_distribution<int> dis(1, range);
                sum = dis(gen);
                this->m_question[i].num2 = sum;
            }
        }
    }
}


