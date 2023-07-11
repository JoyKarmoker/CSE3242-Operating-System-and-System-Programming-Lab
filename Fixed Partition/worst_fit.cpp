#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Block {
    int size;
    int processNo;
};

void input(vector<int>& procSize, vector<Block>& blocks) {
    freopen("worst.txt", "r", stdin);
    int n, b;
    cin >> n >> b;
    procSize.resize(n);
    blocks.resize(b);

    for (int i = 0; i < n; i++)
        cin >> procSize[i];
    for (int i = 0; i < b; i++) {
        cin >> blocks[i].size;
        blocks[i].processNo = -1;
    }
}

bool compareBlocks(const Block& block1, const Block& block2) {
    return block1.size > block2.size;
}

void worstFit(vector<int>& procSize, vector<Block>& blocks) {
    sort(blocks.begin(), blocks.end(), compareBlocks);

    cout << "Block No.\tBlock Size\tProcess No.\n";

    for (int i = 0; i < procSize.size(); i++) {
        int worstIdx = -1;
        for (int j = 0; j < blocks.size(); j++) {
            if (blocks[j].size >= procSize[i]) {
                if (worstIdx == -1 || blocks[j].size > blocks[worstIdx].size) {
                    worstIdx = j;
                }
            }
        }

        if (worstIdx != -1) {
            blocks[worstIdx].processNo = i + 1;
        }
    }

    for (int i = 0; i < blocks.size(); i++) {
        cout << i + 1 << "\t\t" << blocks[i].size << "\t\t";
        if (blocks[i].processNo == -1)
            cout << "Not allocated";
        else
            cout << "P" << blocks[i].processNo;
        cout << "\n";
    }
}

int main() {
    vector<int> procSize;
    vector<Block> blocks;

    input(procSize, blocks);
    worstFit(procSize, blocks);

    return 0;
}
