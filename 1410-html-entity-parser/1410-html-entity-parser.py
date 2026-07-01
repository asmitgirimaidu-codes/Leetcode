class Solution(object):
    def entityParser(self, text):
        """
        :type text: str
        :rtype: str
        """
        entities = {
            "&quot;": '"',
            "&apos;": "'",
            "&amp;": "&",
            "&gt;": ">",
            "&lt;": "<",
            "&frasl;": "/"
        }
        
        i = 0
        result = []
        n = len(text)
        
        while i < n:
            found = False
            # Check for possible entities starting at index i
            if text[i] == '&':
                for entity, char in entities.items():
                    if text[i:i+len(entity)] == entity:
                        result.append(char)
                        i += len(entity)
                        found = True
                        break
            
            if not found:
                result.append(text[i])
                i += 1
                
        return "".join(result)