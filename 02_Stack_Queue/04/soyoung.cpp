int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> truck_queue;         // 모든 트럭
    queue<int> truck_on_queue;      // 다리 위에 있는 트럭
    for (int i = 1; i < truck_weights.size(); i++) {
        truck_queue.push(truck_weights[i]);
    }
    
    // 트럭이 아니면 -1을 넣음
    for (int i = 0; i < bridge_length - 1; i++) {
        truck_on_queue.push(-1);
    }
    truck_on_queue.push(truck_weights[0]);
    
    int answer = 1;
    int current_weight = truck_weights[0];
    int on_truck_count = 1;
    while(true) {
        answer++;   // 1초 증가
        
        // 현재 다리를 다 지난 트럭 무게 정산
        int current_on_truck = truck_on_queue.front();
        if (current_on_truck != -1) {
            current_weight -= current_on_truck;
            on_truck_count--;
        }
        truck_on_queue.pop();
        
        // 새롭게 오를 트럭 무게 정산
        if (!truck_queue.empty()) {
            int current_truck = truck_queue.front();
            if (current_weight + current_truck <= weight) {
                current_weight += current_truck;
                truck_queue.pop();
                truck_on_queue.push(current_truck);
                on_truck_count++;
            } else {
                truck_on_queue.push(-1);
            }
        }     
        
        // check status
        if (truck_queue.empty() && on_truck_count == 0)
            return answer;
    }
}
