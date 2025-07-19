class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        folder.sort()
        res =[]
        res.append(folder[0])
        
        for path in folder[1::]:
            if not path.startswith(res[-1] + '/'):
                res.append(path) 
        return res