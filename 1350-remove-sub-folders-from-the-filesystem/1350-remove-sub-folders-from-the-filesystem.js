/**
 * @param {string[]} folder
 * @return {string[]}
 */
var removeSubfolders = function (folder) {
    folder.sort();
    const result = [];

    for (const f of folder) {
        if (result.length === 0 || !f.startsWith(result[result.length - 1] + '/'))
            result.push(f);
    }

    return result;
};