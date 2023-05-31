const merge = (nums1, m, nums2, n) => {
  let idx1 = m - 1,
    idx2 = n - 1,
    idxT = m + n - 1;

  while (idx1 >= 0 && idx2 >= 0) {
    if (nums1[idx1] < nums2[idx2]) {
      nums1[idxT] = nums2[idx2];
      idx2--;
      idxT--;
    } else {
      nums1[idxT] = nums1[idx1];
      idx1--;
      idxT--;
    }
  }
  while (idx2 >= 0) {
    nums1[idxT] = nums2[idx2];
    idx2--;
    idxT--;
  }
};
