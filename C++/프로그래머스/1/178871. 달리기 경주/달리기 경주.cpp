#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> playerIdxMap;
    
    // 1. 현재 등수를 map에 저장
    for (int i = 0; i < players.size(); ++i)
    {
        playerIdxMap[players[i]] = i;
    }
    
    // 2. 등수 변경
    for (const string& call : callings)
    {
        int currentIdx = playerIdxMap[call];
        
        int frontIdx = currentIdx - 1;
        string frontPlayer = players[frontIdx];
        
        players[frontIdx] = call;
        players[currentIdx] = frontPlayer;
        
        playerIdxMap[call] = frontIdx;
        playerIdxMap[frontPlayer] = currentIdx;
    }
    
    return players;
}