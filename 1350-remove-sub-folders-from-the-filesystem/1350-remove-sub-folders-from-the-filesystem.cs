public class Solution {
    public IList<string> RemoveSubfolders(string[] folder) {
        IList<string> result = new List<string>();
        HashSet<string> prefix = new();
        foreach (var f in folder) prefix.Add(f);
        foreach (var f in folder) {
            var names = f.Split('/');
            string path = string.Empty;
            bool shouldInclude = true;
            for (int i = 1; i < names.Length - 1; i++) {
                path += "/" + names[i];
                if (path == f) continue;
                if (prefix.Contains(path)) {
                    shouldInclude = false;
                    break;
                }
            }
            if (shouldInclude) result.Add(f);
        }
        return result;
    }
}