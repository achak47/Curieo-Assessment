#include <bits/stdc++.h>

using namespace std;

class Error_log {
  unordered_map<string, vector<vector<double>>> logs;
  unordered_map<string, vector<uint64_t>> logsid;
  vector<vector<double>> glogs;
  vector<uint64_t> glogsid;
  unordered_set<string> types;

  double dmin(double a, double b) { return a > b ? b : a; }
  double dmax(double a, double b) { return a > b ? a : b; }

public:
  void add(uint64_t timestamp, string type, double duration) {
    // cout<<timestamp<<" "<<type<<" "<<type.length()<<" "<<duration<<endl ;
    if (type[0] == ' ')
      type = type.substr(1);
    if (types.find(type) != types.end()) {
      int s = logs[type].size();
      double avg = (logs[type][s - 1][0] * s + duration) / (s + 1),
             m = dmin(duration, logs[type][s - 1][1]),
             M = dmax(duration, logs[type][s - 1][2]);
      logs[type].push_back({avg, m, M, duration});
      logsid[type].push_back(timestamp);
    } else {
      types.insert(type);
      logs[type].push_back({duration, duration, duration, duration});
      logsid[type].push_back(timestamp);
    }
    int s = glogs.size();
    double avg = s > 0 ? (glogs[s - 1][0] * s + duration) / (s + 1) : duration,
           m = s > 0 ? dmin(duration, glogs[s - 1][1]) : duration,
           M = s > 0 ? dmax(duration, glogs[s - 1][2]) : duration;
    glogs.push_back({avg, m, M, duration});
    glogsid.push_back(timestamp);
  }
  vector<double> log_type(string type) {
    // cout<<type<<" "<<type.length()<<endl ;
    if (type[0] == ' ')
      type = type.substr(1);
    if (types.find(type) == types.end())
      return {};
    int s = logs[type].size();
    // cout<<s<<endl ;
    return logs[type][s - 1];
  }
  vector<double> before(uint64_t timestamp, string type) {
    // cout<<timestamp ;
    if (type[0] == ' ')
      type = type.substr(1);
    vector<vector<double>> v1 = logs[type];
    vector<uint64_t> v = logsid[type];
    int l = lower_bound(v.begin(), v.end(), timestamp) - v.begin();
    // cout<<l ;
    if (l - 1 < 0)
      return {};
    return v1[l - 1];
  }
  vector<double> after(uint64_t timestamp, string type) {
    if (type[0] == ' ')
      type = type.substr(1);
    vector<vector<double>> v1 = logs[type];
    vector<uint64_t> v = logsid[type];
    int s = v.size();
    int u = upper_bound(v.begin(), v.end(), timestamp) - v.begin();
    if (u >= v.size())
      return {};
    double m = INT_MAX, M = INT_MIN;
    for (int i = u; i < v.size(); i++) {
      m = dmin(m, v1[i][3]);
      M = dmax(M, v1[i][3]);
    }
    double mean;
    if (u == 0) {
      mean = v1[s - 1][0];
    } else {
      mean = (v1[u - 1][0] * (u)-v1[s - 1][0] * (s)) / (s - u);
    }
    return {mean, m, M};
  }
  vector<double> before(uint64_t timestamp) {
    int l = lower_bound(glogsid.begin(), glogsid.end(), timestamp) -
            glogsid.begin();
    // cout<<l ;
    if (l - 1 < 0)
      return {};
    return glogs[l - 1];
  }
  vector<double> after(uint64_t timestamp) {
    vector<vector<double>> v1 = glogs;
    vector<uint64_t> v = glogsid;
    int s = v.size();
    int u = upper_bound(v.begin(), v.end(), timestamp) - v.begin();
    if (u >= v.size())
      return {};
    double m = INT_MAX, M = INT_MIN;
    for (int i = u; i < v.size(); i++) {
      m = dmin(m, v1[i][3]);
      M = dmax(M, v1[i][3]);
    }
    double mean;
    if (u == 0) {
      mean = v1[s - 1][0];
    } else {
      mean = (v1[u - 1][0] * (u)-v1[s - 1][0] * (s)) / (s - u);
    }
    return {mean, m, M};
  }
};