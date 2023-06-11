class SnapshotArray {
public:
    
    vector<map<int,int>> v;
    int snaps;
    
    SnapshotArray(int length) {
        vector<map<int,int>> temp(length);
        v=temp;
        snaps=0;
    }
    
    void set(int index, int val) {
        v[index][snaps]=val;
    }
    
    int snap() {
        
        snaps++;
        return snaps-1;
        
    }
    
    int get(int index, int snap_id) {
        
        while(v[index].find(snap_id)==v[index].end())
        {
            snap_id--;
            if(snap_id==-1)
                return 0;
        }
        
        return v[index][snap_id];
    }
};