/* Excerpt from file /usr/src/sys/miscfs/procfs/procfs_vnops.c *//* Implement poll for procfs -- not as featureful as it could be, but a start
 * for now, it only checks for a process stopping via STOPEVENT().
 */
static int
procfs_poll(ap)
  struct vop_poll_args /* {
    struct vnode *a_vp;
    int a_events;
    struct ucred *a_cred;
    struct proc *a_p;
  } */ *ap;
{
  struct pfsnode *pfs = VTOPFS(ap->a_vp);
  struct proc *procp, *p;
  int error;
  p = ap->a_p;
  procp = pfind(pfs->pfs_pid);
  if (procp == NULL) {
    return ENOTTY;
  }
  if (!CHECKIO(p, procp))
    return EPERM;
  if (!procp->p_ev) {
    get_procfs_event(procp);
  } else if (procp->p_ev->p_step) {
    return (ap->a_events & (POLLRDNORM | POLLWRNORM));
  }
  selrecord(p, &procp->p_ev->p_sel);
  return 0;
}
