class MyCircularDeque {
public:
    vector<int>ar;
    int F, R, sz;
    MyCircularDeque(int k) {
        
        vector<int>arr(k, -1);
        ar = arr;
        set(k/2, k/2, k);
    }
    void set(int f, int r, int s)
    {
        F = f;
        R = r;
        sz = s;
    }
    
    bool insertFront(int value) {

        

        if(ar[F]==-1)
        {
            cout<<F<<" "<<R<<endl;
            ar[F] = value;
            return true;
        }
        else
        {
            int ff = F;
            F = ((F-1)+sz)%sz;
            cout<<F<<" "<<R<<endl;
            if(F!=R)
            {
                ar[F] = value;
                return true;
            }
            else
            {
                F = ff;
                return false;
            }
        }
        return false;
    }
    
    bool insertLast(int value) {
        //cout<<F<<" "<<R<<endl;
        if(ar[R]==-1)
        {
            cout<<F<<" "<<R<<endl;
            ar[R] = value;
            return true;
        }
        else
        {
            int rr = R;
            R = (R+1)%sz;
            cout<<F<<" "<<R<<endl;
            if(F!=R)
            {
                ar[R] = value;
                return true;
            }
            else
            {
                R = rr;
                return false;
            }
        }
        return false;
    }
    
    bool deleteFront() {
        if(ar[F]==-1)
        {
            return false;
        }
        else
        {
            ar[F] = -1;
            if(F!=R)
                F = (F+1)%sz;
            return true;
        }
        return false;
    }
    
    bool deleteLast() {
        if(ar[R]==-1)
        {
            return false;
        }
        else
        {
            ar[R] = -1;
            if(F!=R)
                R = ((R-1)+sz)%sz;
            return true;
        }
        return false;
    }
    
    int getFront() {
        return ar[F];
    }
    
    int getRear() {
        return ar[R];
    }
    
    bool isEmpty() {
        if(F==R && ar[F]==-1)return true;
        return false;
    }
    
    bool isFull() {
        if(sz==1 && ar[F]!=-1)return true;
        if(R<F && F-R==1)return true;
        if(F==0 && R==sz-1)return true;
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
