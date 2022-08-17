vector<int> Solution::grayCode(int A) {
    
            vector<int> result(1, 0);  
            for (int i = 0; i < A; i++) {
                int curSize = result.size();
                // push back all element in result in reverse order
                for (int j = curSize - 1; j >= 0; j--) {
                    result.push_back(result[j] + (1 << i));
                } 
            }
            return result;
}

