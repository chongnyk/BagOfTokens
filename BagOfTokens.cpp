class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int pTotal = accumulate(tokens.begin(), tokens.end(), 0);
        int pBudget = power;
        int score = 0, maxScore = 0;
        sort(tokens.begin(), tokens.end(), greater<int>());
        int fDown = 0, fUp = tokens.size() - 1;
        while(fDown <= fUp){
            if(tokens[fUp] <= pBudget){
                pBudget -= tokens[fUp];
                pTotal -= tokens[fUp];
                score++;
                fUp--;
                maxScore = max(maxScore, score);
            }
            else if(tokens[fUp] > pBudget && score > 0){
                score--;
                pBudget += tokens[fDown];
                pTotal -= tokens[fUp];
                fDown++;
            }
            else if(pBudget >= pTotal){
                return tokens.size() - fDown;
            }
            else if(tokens[fUp] > pBudget && score == 0){
                break;
            }

            cout << pBudget << ' ' << score << ' ' << pTotal << '\n' << fDown << ' ' << fUp << '\n';
        }
        return maxScore;
    }
};
