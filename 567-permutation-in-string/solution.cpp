class Solution {
public:
    bool isSame(int freq1[], int  freq2[]){
        for(int i=0; i<26; i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }

        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};

        for(int i=0; i<s1.length(); i++){
            int index = s1[i] - 'a';
            freq[index]++;
        }

        int winSize = s1.length();

        for(int i=0; i <s2.length(); i++){
            int winIdx = 0, idx = i;
            int winFreq[26] = {0};

            while(winIdx < winSize && idx < s2.length()){
                winFreq[s2[idx] - 'a']++;
                winIdx++;
                idx++;
            }

            if(isSame(winFreq, freq)){
                return true ;
            }
        }

        return false;
    }
};