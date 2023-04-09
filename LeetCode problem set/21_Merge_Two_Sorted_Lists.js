// https://leetcode.com/problems/merge-two-sorted-lists/

const mergeTwoLists = (list1, list2) => {
  if (!list1) return list2;
  if (!list2) return list1;

  const mergedList = [];
  let idx1 = 0,
    idx2 = 0,
    idxT = 0;

  while (list1.length && list2.length) {
    if (list1[idx1] <= list2[idx2]) {
      mergedList[idxT] = list1[idx1];
      idx1++;
      idxT++;
    } else {
      mergedList[idxT] = list2[idx2];
      idx2++;
      idxT++;
    }
  }

  while (idx1 < list1.length) {
    mergedList[idxT] = list1[idx1];
    idx1++;
    idxT++;
  }

  while (idx2 < list2.length) {
    mergedList[idxT] = list2[idx2];
    idx2++;
    idxT++;
  }

  return mergedList;
};

const list1 = [1, 2, 4];
const list2 = [1, 3, 4];

const list = mergeTwoLists(list1, list2);
