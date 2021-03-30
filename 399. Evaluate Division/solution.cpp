class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, map<string, double>> graph = buildGraph(equations, values);
        vector<double> result;
        for (int i = 0; i < queries.size(); i++) {
            set<string> visited;
            result.push_back(calculate(graph, queries[i][0], queries[i][1], visited));
        }
        return result;
    }
    
    double calculate(map<string, map<string, double>>& graph, const string& from, const string& to, set<string>& visited) {
        if (graph.find(from) == graph.end() || graph.find(to) == graph.end()) { return -1; }
        if (graph[from].find(to) != graph[from].end()) { return graph[from][to]; }
        // cout << "from: " << from << " to: " << to << endl;
        visited.insert(from);
        map<string, double>& tos = graph[from];
        auto it = tos.begin();
        while (it != tos.end()) {
            if (visited.find(it->first) == visited.end()) {
                double value = calculate(graph, it->first, to, visited);
                if (value != -1) {
                    return value * tos[it->first];
                }
            }
            ++it;
        }
        return -1;
    }
    
    map<string, map<string, double>> buildGraph(vector<vector<string>>& equations, vector<double>& values) {
        map<string, map<string, double>> result;
        for (int i = 0; i < equations.size(); i++) {
            string from = equations[i][0];
            string to = equations[i][1];
            double value = values[i];
            result[from][to] = value;
            result[to][from] = 1.0 / value; 
        }
        return result;
    }
};
