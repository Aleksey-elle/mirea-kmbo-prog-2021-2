#include <iostream>
#include <map>
#include <string>

#include "common.h"

using namespace std;

/// ������� -> { ������� -> ��� }


graph build_graph(std::istream &is) {
    /// TODO 1
    /// ��������� ������� �����; ���� �� �� �������� ��������� � �������� ������ �����, � ����� ��� �����
    std::string src = ""; /// �������� �������
    std::string dst = ""; /// �������� �������
    float weight = 0;    /// ��� ����� src-dst

    is >> src;

    graph graph;

    /// ���������, ���������� �� �������� �������; ���� ��� - ���������; ���� ��, ���������� ���������
    graph.insert(std::pair<std::string, weight_map>(dst, weight_map()));

    /// ���������, ���������� �� �������� �������; ���� ��� - ���������; ���� ��, ���������� ���������
    std::pair<graph::iterator, bool> insres = graph.insert(std::pair<std::string, weight_map>(dst, weight_map()));

    /// ��������� ������ ��� �������� ������� � ��� � ��������
    insres.first->second.insert(std::pair<std::string, float>(dst, weight));

    /// ��������� � ��������� ������
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        cerr << "Need at least 2 points to search" << endl;
        return 1;
    }

    /// 1. ��������� �������� ������ � ����, �������� ���� � ����������� ������
    ///     ��������� ��������� � stdin  (std::cin), ��������� �������, ��������� ������
    ///     ������ ������ - ��� ��� ��������: �������� �������, �������� �������, ���
    auto graph = build_graph(cin);

    /// 2. ������������ � �������������� �������� � �������� ������� ����� ��� ����������� ����
    ///     ��� ��������� ��������� ������
    string src_name(argv[1]);
    string dst_name(argv[2]);

    auto src_it = graph.find(src_name);
    auto dst_it = graph.find(dst_name);

    if (src_it == graph.end()) {
        cerr << "Unknown source: " << src_name << endl;
        return 1;
    }
    if (dst_it == graph.end()) {
        cerr << "Unknown destination: " << dst_name << endl;
        return 1;
    }

    /// 3. ������� ������� ������ ����
    ///     � ����������
    auto result = shortest_length(graph, src_it->first, dst_it->first);

    /// 4. ������� ���������
    cout << result << endl;
    return 0;
}
