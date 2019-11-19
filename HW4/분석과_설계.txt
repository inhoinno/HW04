 1. 문제 이해 분석
 허프만트리를 만들기
    기능
    .1   100글자 이상이 포함된 "좋아하는 글" 을 입력 받아
    .2   입력받은 글의 Huffman Code 를 출력
    .3   출력된 코드를 입력받아서 문자열을 출력
    평가
    .1   입력된 문자열이 100자 이상이어야 합니다.
    .2   입력된 문자열과 출력된 문자열이 동일한가?
    .3   ASCII문자열 코딩과 Huffman coding 과 크기비교

기능.1 100자 이상의 "좋아하는 글"을 입력 받아야 함.
    -> 만약 100자 이상이 아니라면 다시 입력받는 입력함수의 구현 ....1.
기능.2 입력받은 글의 Huffman Code 를 출력
    -> 입력받은 글(String)을 HuffmanCode(Binary Tree)로 변환해주는 함수의 구현 .....2.

    /* ============================== HUFFMAN TREE ==============================*/
        //정의. 아스키코드를 더욱 효과적으로 압축하는 알고리즘이라 할 수 있다. 스토리지 확보가 TOP PRIORITY 최대장점이다.
        //방법. 아스키 코드의 각 문자 별로 빈도수 (CHARACTER WEIGHT)를 매긴다.
        //      CHARACTER WEIGHT에 따라서 트리를 만듬. 다음과 같은 방법.
        // 1.   First, we orgaanize the enter charcter set into row , ordered according to frequency from highest to lowest(or vice versa)
        // 2.   Next, we find the TWO NODES with the smallest combined frequency weights and join then to form a third node, resulting in a
        ///     simple two-level tree. 
        ///     the weight of the new node is the combined weights of the original two nodes.  .... 
        ///            //->think apropriate DS for this organization of table
        ///     This node, one level up from the leaves,  is eligible to be combined with other node 
        ///             //->how feature the tree + node(level 0) or tree(level 0) + tree(level 0)?? ->> let it node+node.
        ///     Remember, the sum of weights of the two nodes chosen must be smaller than the combination of any other possible choices
        // 3.   We repeat step 2 until all of the node, on every level, are combined in to a single tree.
        /1  HuffmanCode: 빈도수별 문자를 압축(Tree형태로 나옴) 를 구현함에 있어 "문자의 빈도수"를 저장해야함을 알 수 있음
            -> 문자열을 입력받아서(String) , 그것을 빈도수 테이블(Array)형태로 변환하는 함수 필요.....2.1 
            -> 빈도수 테이블의 자료구조를 설계해야 함을 알 수 있음. .. 2.2 //vector -> C++
                    //-> 빈도수 테이블은 노드가 선택되면 테이블에 두개의 노드가 pop이 되고 (pop된 )새로운 노드가 push 되어야함. 
        /2  HuffmanCode: 최소 빈도수 2개를 선택해서 트리형태로 만들어주어야함. 
            -> 입력 스트링의 빈도수 테이블을 인자로 받아 허프만 코드를 만드는 함수가 요구됨.  .........2.3 *(Critical Function)
            -> 빈도수 테이블 자료구조중에서 최소 빈도수인 두개를 선택해야함. 선택시에 여려가지 분기가 요구됨.
            -> 선택한 두 개의 노드 혹은 트리를 하나의 트리로 만들어주는 함수가 요구됨. .......2.4 *(Critical Function)
        /3  만든 트리의 노드에는 각각의 빈도수를 합친 수의 정보를 가지고 있어야함. ...2.1
            -> 만든 노드 또한 /2 실행시 들어가는 노드임. 따라서 두개를 pop하고 만든 하나를 다시 push해야함. ....2.1자료구조의 adt 
            -> loop til 자료구조 내 노드 수 == 1일때 까지 순회 하며 노드들끼리 연결, (트리 제작) .......2.5 while 하면서 왼쪽과 오른쪽을 연결해줌


기능3. 만들어진 Huffman Tree를 이용해서 입력받은 문자열을 Huffman Code 로 변환해야함.
//* Now Huff Tree is set *//
    -> 원래 문자열 "좋아하는글"의 문자 하나를 읽고, 해당 문자가 있는 리프 노드까지 순회. *순회함수 요구(Tree Traversal.....3.1 
        -> ***/바이너리트리지만 0과1.. 판단? 허프만 트리는 만들어 질 때 0이랑 1을 주는데 그 조건을 여기서도 재활용이 가능할까?/) .......3.1
    -> 리프노드까지 가면서 왼쪽자식 0 , 오른쪽 자식 1 이렇게 번호를 주기하면서 노드를 search. ....3.1
        -> traversal 구현, 번호 주기를 저장할 자료구조 (stack?) 필요. ........3.2DS in func.3.1.
        -> 주기한 자료구조내용은 곧 그 문자 하나의 Huffman code 가 됨. //a(67?) -> 001()
        -> 생성된 HuffmanCode를 /1. fwrite 2. 문자열 배열 / 을 사용하여저장. //DS
    -> 문자열 끝날때까지 읽음. 루프가 종료되면 /DS/ 배열 or 파일에는 그 것에 해당하는 Huffman Code가 존재.

기능4. Reverse Huffman Code 허프만 코드를 읽어서 문자열로 변환. ......4. 
    -> 이때 그 문자열 해독한 **허프만 트리가 반드시 존재해야*** 변환가능. .4.need .DS tree->root
    -> Huffman code/DS/ 를 해독하면서 배열의 값에 따라서 트리 분기 판단/0왼쪽, 1오른쪽/ 하면서 리프노드에 도달 할 때까지 트리 순회
    -> 순회시 다음 문자를 +1하게 되고 리프노드라면 그 노드가 가지고 있는 문자를 출력. 이후, offset부터 다시 루프.
    -> loop는  문자열이 end될때 까지. 
    -> loop종료시에는 해당 문자열에 해당하는 허프만 코드가 출력된다. /출력이 싫으면 또 배열에 저장하던가./ 

