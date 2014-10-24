/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == NULL) return NULL;
        queue<UndirectedGraphNode *> qf, qc;
        set<UndirectedGraphNode *> gset;
        map<int, UndirectedGraphNode *> gc;
        UndirectedGraphNode *ret = new UndirectedGraphNode(node->label);
        gc[ret->label] = ret;
        qf.push(node);
        qc.push(ret);
        while (!qf.empty()) {
			UndirectedGraphNode *tmpf = qf.front();
            UndirectedGraphNode *tmpc = qc.front();
            if (gset.find(tmpf) == gset.end()) {
				for (int i = 0; i < tmpf->neighbors.size(); i++) {
					UndirectedGraphNode *tmp;
                    if (gc.find(tmpf->neighbors[i]->label) != gc.end())
                    	tmp = gc[tmpf->neighbors[i]->label];
					else {
						tmp = new UndirectedGraphNode(tmpf->neighbors[i]->label);
                        gc[tmp->label] = tmp;
                    }
                    tmpc->neighbors.push_back(tmp);
                    qf.push(tmpf->neighbors[i]);
                    qc.push(tmp);
                }
                gset.insert(tmpf);
            }
        	qf.pop();
            qc.pop();
        }
    	return ret;
    }
};
