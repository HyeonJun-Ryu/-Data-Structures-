# -자료구조(Data-Structures)-
# Sorting.cpp

# 1. selectionSort(선택 정렬) 
시간복잡도: O(N^2)   공간복잡도: O(N)  
  
① 정렬 되지 않은 인덱스의 맨앞에서 부터,&nbsp;이를 포함한 그 이후의 배열값 중 가장 작은 값을 찾아간다.  
(정렬되지 않은 인덱스의 맨 앞은, 초기 입력에서는 배열의 시작위치일 것이다.)  
② 가장 작은 값을 찾으면, 그 값을 현재 인덱스의 값과 바꿔준다.  
③ 다음 인덱스에서 위 과정을 반복해준다.  
  
![image](https://user-images.githubusercontent.com/74097144/149055813-467af0ce-b818-4967-9e44-b8de66d9df43.gif)


# 2. insertionSort(삽입 정렬)  
시간복잡도: O(N^2), 하지만 이미 정렬되어 있는 경우 O(N)   
공간복잡도: O(N)  
  
① 삽입 정렬은 두 번째 인덱스부터 시작한다. 현재 인덱스는 별도의 변수에 저장해주고, 비교 인덱스를 현재 인덱스 -1로 잡는다.  
② 별도로 저장해 둔 삽입을 위한 변수와, 비교 인덱스의 배열 값을 비교한다.    
③ 삽입 변수의 값이 더 작으면 현재 인덱스로 비교 인덱스의 값을 저장해주고, 비교 인덱스를 -1하여 비교를 반복한다.  
④ 만약 삽입 변수가 더 크면, 비교 인덱스+1에 삽입 변수를 저장한다.   
  
![image](https://user-images.githubusercontent.com/74097144/149076855-cb285a91-9096-4d18-9360-dd1e226ba5f0.gif)


# 3. bubbleSort(버블 정렬)
시간복잡도: O(N^2)   공간복잡도: O(N)  

① 삽입 정렬은 두 번째 인덱스부터 시작한다. 현재 인덱스 값과, 바로 이전의 인덱스 값을 비교한다.   
② 만약 이전 인덱스가 더 크면, 현재 인덱스와 바꿔준다.   
③ 현재 인덱스가 더 크면, 교환하지 않고 다음 두 연속된 배열값을 비교한다.   
④ 이를 (전체 배열의 크기 - 현재까지 순환한 바퀴 수)만큼 반복한다.   
  
![image](https://user-images.githubusercontent.com/74097144/149077799-452c544f-1803-4224-b5cc-f96a45c331a1.gif)


# 4. quickSort(퀵 정렬)
시간복잡도: O(NlogN), 최악의 경우(이미 정렬되어 있는 경우) O(N^2)
공간복잡도: O(N)  
  
① pivot point로 잡을 배열의 값 하나를 정한다. 보통 맨 앞이나 맨 뒤, 혹은 전체 배열 값 중 중간값이나나 랜덤 값으로 정한다.  
② 분할을 진행하기에 앞서, 비교를 진행하기 위해 가장&nbsp;왼쪽 배열의 인덱스를 저장하는 left 변수, 가장 오른쪽 배열의 인덱스를 저장한 right변수를 생성한다.   
③ right부터 비교를 진행한다. 비교는 right가 left보다 클 때만 반복하며. 비교한 배열값이 pivot point보다 크면 right를 하나 감소시키고 비교를 반복한다.  
⑤ left 인덱스의 값과 right 인덱스의 값을 바꿔준다.  
⑥ 3,4,5 과정을 left<right가 만족 할 때 까지 반복한다.  
⑦ 위 과정이 끝나면 left의 값과 pivot point를 바꿔준다.  
⑧ 맨 왼쪽부터 left - 1까지, left+1부터 맨 오른쪽까지로 나눠 퀵 정렬을 반복한다.  
(분할과 동시에 정렬을 진행하는 알고리즘)
  
![image](https://user-images.githubusercontent.com/74097144/149078217-c182b8a8-b662-4e42-9845-ba3109e652e9.gif)


# 5. mergeSort(합병정렬)
시간복잡도: O(NlogN)  
공간복잡도: O(N)   

![image](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=http%3A%2F%2Fcfile6.uf.tistory.com%2Fimage%2F2748243C58BBF920230735)  
** 합병 정렬에 사용되는 배열은 '전역 변수'로 선언해야 한다.

# 6. countingSort(계수정렬)
시간복잡도: O(N)
공간복잡도: O(K)   (배열 최대값 K일 때, K+1 길이의 배열이 필요하므로)  

카운팅 소트는 수의 입력 범위가 비교적 작고 입력 갯수가 많을 때 사용할 수 있는 정렬 방법입니다.  
입력되는 수가 1 이상 10000 이하의 수이므로 10001개의 배열 크기를 가지는 count 배열을 선언하고 값을 0으로 초기화 합니다.  
하나씩 입력받으면서 해당 입력 값을 인덱스로 하는 배열 값을 증가시킵니다.  
이때 입력받는 값들은 배열 값을 증가시키는데만 사용되고 저장하지 않습니다.  
입력이 끝나면 1부터 10000까지 모든 배열값을 확인하고 0이 아니라면 그 값만큼 반복해서 출력합니다.  
list, arr, sum 전부 필요 없는 배열입니다. count 배열 하나면 됩니다.  
    
# #내용 출처: https://hsp1116.tistory.com/33, https://ko.wikipedia.org/wiki/합병_정렬
  
# Usage

::input::  
5  
20 10 35 30 7  
1 (selectionSort) / 2 (insertinSort) / 3 (bubbleSort) / 4 (quickSort) / 5 (mergeSort) / 6 (countSort)


::output::  
7 10 20 30 35   
