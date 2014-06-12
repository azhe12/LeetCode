/*  azhe
 *  2014/6/12
 *  https://oj.leetcode.com/problems/word-ladder/
 *  start:  hit
 *  end:    cog
 *  dict:   hot, dot, dog, lot, log
 *  Note: 无权图的最短路径问题, 抽象:
 *  每个单词临接的单词, 即可以通过改变一位字母而得到的其他单词
 *  1. 创建临接表
 *  2. 依据临接表计算最短路径
 * */
#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    typedef map<string, vector<string> > Map;
    Map generateAdjMap(unordered_set<string> &dict)
    {
        Map adjMap;
        int wordsize = dict.begin()->size();        /*单词的长度*/
        /*  计算临接单词，第一步：
         *  分别去掉单词的每一位如果余下的单词相同，则这些单词临接，放在partMap中
         *  如删除第一个字母:ot对应hot dot lot; og对应dog, log, cog
         *  */
        for (int i = 0; i < wordsize; i++) {
            Map partMap;
            for (unordered_set<string>::iterator it = dict.begin(); it != dict.end(); it++) {
                string tmp = *it;
                tmp.erase(i, 1);
                partMap[tmp].push_back(*it);
            }
#if 0
            /*debug: print partMap*/
            cout<<"partition: "<<endl;
            for (Map::iterator it = partMap.begin(); it != partMap.end(); it++) {
                cout<<it->first<<" : ";
                vector<string> & words = it->second;
                for (int i = 0; i < words.size(); i++) {
                    cout<<words[i]<<" ";
                }
                cout<<endl;
            }
#endif

            /*  第二步
             *  利用partMap生成临接表
             * */
            for (Map::iterator it = partMap.begin(); it != partMap.end(); it++) {
                vector<string> words = it->second;
                if (words.size() >= 2) {    /*表示有临接的单词*/

                    for (int i = 0; i < words.size(); i++) {
                        for (int j = i+1; j < words.size(); j++) {
                            adjMap[words[i]].push_back(words[j]);   /*将这些words相互放到对方的临接表中*/
                            adjMap[words[j]].push_back(words[i]);
                        }
                    }
                }
            }
        }
#if 0
        /*debug: print adj map*/
        cout<<"Adj : "<<endl;
        for (Map::iterator it = adjMap.begin(); it != adjMap.end(); it++) {
            cout<<it->first<<" : ";
            vector<string> & words = it->second;
            for (int i = 0; i < words.size(); i++) {
                cout<<words[i]<<" ";
            }
            cout<<endl;
        }
#endif
        return adjMap;
    }

    /*无权图的单源最短路径*/
    int shotestPath(string & start, string & end, Map & adjMap)
    {
        map<string, int> dist;  /*表示不同单词距离start的距离， 默认初始化为0*/
        queue<string> q;
        q.push(start);
        dist[start] = 1;    /*start的dist为1*/
        while (!q.empty()) {
            string word = q.front();
            q.pop();

            if (word == end)        /*找到结果*/
                return dist[word];
            vector<string> adjs = adjMap[word];
            for (int i = 0; i < adjs.size(); i++) {     /*所有临接的且未被访问的word，其dist加1*/
                if (dist[adjs[i]] == 0) {   /*说明没有被访问过*/
                    q.push(adjs[i]);
                    dist[adjs[i]] = dist[word] + 1;
                }
            }
        }
        /*未找到end*/
        return 0;
    }

    int ladderLength(string start, string end, unordered_set<string> &dict) {
        Map adjMap;
        if (start == end)
            return 1;
        if (dict.size() == 0)
            return 0;
        /*start和end默认已经在dict中*/
        //dict.insert(start);     [>将start, end也放到dict中<]
        //dict.insert(end);

        adjMap = generateAdjMap(dict);
        return shotestPath(start, end, adjMap);
    }
};

int main()
{
    unordered_set<string> dict;
#if 1
    dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("lot");
    dict.insert("log");
    dict.insert("hit");
    dict.insert("cog");

    string start("hit");
    string end("cog");
#else
    dict.insert("talk");
    dict.insert("tons");
    dict.insert("fall");
    dict.insert("tail");
    dict.insert("gale");
    dict.insert("hall");
    dict.insert("negs");

    string start("talk");
    string end("tail");
#endif
    Solution so;
    cout<<"Result: "<<so.ladderLength(start, end, dict)<<endl;
}
