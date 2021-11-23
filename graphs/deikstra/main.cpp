#include <algorithm>
#include <limits>
#include <map>
#include <set>

#include <common.h>

/// typedef std::map<std::string, float> weight_map;    /// �������� ������� -> ��� ����� � ���� �������
/// typedef std::map<std::string, weight_map> graph;    /// �������� ������� -> ����� ������, � ������� ����� ������� �� ������

float DLL_EXPORT shortest_length(const graph &graph, const std::string &src, const std::string &dst) {
    std::map<std::string, float> labels;
    std::set<std::string> tovisit;

    /// ���������� �����
    for (const auto &kv : graph) {
        if (kv.first == src)
            labels[kv.first] = 0;
        else
            labels[kv.first] = std::numeric_limits<float>::infinity();
        tovisit.insert(kv.first);
    }

    while (tovisit.size() > 0) {
        /// 1. �������� �� ���������� ������� � ���������� ������
        auto vi = std::min_element(tovisit.begin(), tovisit.end(),
                   [labels](const std::string &v1, const std::string &v2) { return labels.at(v1) < labels.at(v2); });
        /// 2. ��������� ����� ��� �������, ��� ������� ������ ���������� ����������� �����, ���� ��� ������ ������������
        for (const auto &neighbor : graph.at(*vi)) {
            if (!tovisit.find(neighbor.first))
                continue;
            /// neighbor.first - ��� �������� �������
            /// neighbor.second - ���������� �� �������� �������

            labels[neighbor.first] = std::min(labels[*vi] + neighbor.second, labels[neighbor.first]);
        }
    }

    return 0;
}

extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}
