        y  	$      ���������)��%���u���:�(            (�/�`$}# jCl-���
�br�mt_aߡ��H0���aD4ȆA�7����#��� � � ���ߖ�{��lJ���Y��|g�3o�S�}�����zrf�ov<߁w���xj؟Cvw�=>�U]Vu��z�&�卿��=:kG���\[�yʂ��OM?KMg&�S�|ji1��������۹Ni�mS�.|���/�d@AF Gr"�2�Bhd2�H�ə�,cX�ȅO]��f��<��Q���<%�Z
/����;�]R�j��}�鄹��fݚ�q�Hd�M���T�EeN����Fs��
���VETfQ,���r��B�eO�ufw��Y-O�)0��.��XԱ���r��q"�e��7�NO�Z~oV��R��PV�B\��\��7��j'�ݽq�8#'�p�Sx���o,�=���b��w�fBţ0�g}U�'�1�C������C6���z�xKkA��j�m�v��$\��;�w�7��y7i�ٵ�r���vG-�+u�7K�'�[�ƅ��M����xK��:���������Y��::�0s=�1����2Gi6��$"E"�OaU��ux�H8ͣ��f�t�4v���V�l��x��U0�g���:�VИ�uq�l,�ĕ���Ā������QXQ���Z˩3�~�=�B-B��s��W|ns�]��3ۥ��`@�.�e�U����P4ny��JIE�3�-&kk��ݻ\~���/�����X��h�@���C)�4�,r�t)���C����;�Q O�7�a��q��9B�j-Pg����!�SȘ���`� 0!;0)C�$"h�����R>�vf˒o"�m)�:�ZT���yD�+P�7��M�(Yp��IW&�� d�q�Ь�#�No��h�hhQ��$�^�0���Ɍ��l�cqQc�0��;!H~0`n�G�s��7TQ���%����'���Uk�p��i��
_�&i����$v�8E�ө��O���ș} �#F��#��T���E(�F�R�<���@ˤܩ~��L�M{���JvY�D�T�;�����ҽ��q��j�.ʴ��ۑ��yT� ����b�x�ܑ���dkE��e�~G��{���    y     u  �      )    ����k{�R�$'��'3��2�k            (�/� }e �  [   �   GArpIpv4Interface:: (Ptr<Node> node, NetDevice *d)
  �     {}
  -  E   {}
 ������`    �    �  �     8   ����B}nU�ɰ	j@t����w�bx            (�/�`�U �M6@� �d�@� K"��C�4�d�����5���q��䃵mʢ_0��@F�Q_x= > > ���d���	�߁�w��Rg�ג���K=ie�^r��I���Q��R�N�o�_@�v�fw%E��rM0l�`3�?��Oa�;��@޺���8��ՙ����m$Ɗy�d��Ho���"��z2T!��Fi)z��.������
�1��x���#ؾ,���~p�����ӬU�DA���?C���lJj!�����@�3����&���BQpY16�J14�Ƥ����/tT��Ӯג�´��! @
�����P-0)�2�c�-���@-p���OPV�-��*���,���,�9 %@0{X������S��Gl?o��y    �     _  �     =   ����oD���Z�+a}�5h~%            (�/� m� ���03q)`��=	-�h�����]�&!��g�rq���m�OG޸�K~/���<!g_cB^l,��T�j ��    �     $  �     \   ����G�.sCp�6�bE���T�펴              �  �   #include "ns3/i-node.h"
         S  �     _   �����%�rB9��\���Ё���!            (�/� XU B��� �"�a���e�O�:�\ȀUa|���晦�6��+%Ξ�t��Q*�"��0��m1��x$��c� i�Bf    X     Q  �     �   �����
��N�n�5�~�mya            (�/� WE "D�� �9�	z���*�jV.d��0>�pe�+ӕ�#�I|����)��EH��L��M�Gb{�; f
�Bf    �     "  �     �   �����p�.t�D��3����;�<c              �  �   #include "ns3/node.h"
    �     *  �     �   �������U��/�"I_u�zO�                    #include "ipv4-l3-protocol.h"
    �     �  �     �   �������
���^����EhW�            (�/� �% 4  �  "   T GetDevice ()->Send (p, hardwareDestination, Ipv4L3Protocol::PROT_NUMBER);
  ?  �   Z GetBroadcast () i�KG�W��8�    �     %  �   	  �   	����o'����qGä�d�              �      #include "arp-private.h"
    �     W  �   
  �   
�������"D@�F ZQ���s�r�            (�/� ^u $  �  G   R Ptr<ArpPrivate> arp = m_node->QueryInterface(::iid);
 07A����    �     �  	�     �   �����Y<�LX��N�$���)�2            (�/�`� u b�-*`i ���ϯFi��k#��!M�+An�V��{�[��By���kU�0g*�j:Ę�4�Ž�p�����P�;�f]�w^q���(�'pOVR[��}���7�4�F����ȝ�����r!��q��K���޲E�EF��F�u���Zg�N�R�N,T��15&���@B��M*�O @' � P�o�`�.���+���Q{pG!3�˳͏B���[�C��ASƉ���    	�     f  �     �   �����ad��.̦����AYV�-t�              h        �  �   N      bool found = arp->Lookup (p, dest, GetDevice (), &hardwareDestination);
    
\     T  �     �   �������uB�����Ķ���H!S9              �  �   #include "ns3/address.h"
  D  j   #      Address hardwareDestination;
    
�     �  	�     �      c`���� �� ���YD>�'�            (�/�`� } b.+pi������g[��wҠ����ſ�	vLVE�C���W@!V�kU�0g*�j6Ę�4�Ž�p�����P�;�f]�w^q���(�'pOVR[��}���7�4�F����ȝ�����r!���q��G���޲E�EF��F�u���Zg�N�R�N,T%��15&���@B��M*�O @' � P�o�`�.���+���Q{pG!3�˳͏B���[�C��ASƉ���    �     �  	�     �   ����t��8:XZ'>��T2t��˜�            (�/�` % �K)*�9	0@	Ȉl�SE���s���L�"��q�<���!�����F��&�p@OvE���IAO�j��d��V׺��eu`������Xk�ƳK'��x#���=���QB֔$�d�nI*�o�w�?�P�[�CŘdurY��k �,_,�b� f�@.�����:�O!�T"�Z�ak�    w     e  	|     �   �����;;j.o~��e�c������            (�/� n� $  �  �   b MakeCallback (&NetDevice::CreateTraceResolver, PeekPointer (G ())));
 ��    �     f  	�     &   �����5�7�W���_=[SW��uq�            (�/� t� �  �  �   h 
 if (dest.IsBroadcast () ||SubnetDirectedGetNetworkMask ()) )
 S	����m�    B     �  	^     -   ����I����j�	�D�[���}�            (�/� �% "�#�'��e�p9ҏ�屸���ȉ��C��:�0��JZ�����{ʍ�Mᾕ��*�G�������c�4t��5x�d�Cү�W�9��7�N[�Q�fe�6��i�jP���? pBP
���=DE    �     ^  	i     5   ������+����N�s�~$p�|�            (�/� w� �  	     Ptr<TraceResolver>
  J  �   L  Ptr<Composite r = Create();
m��am2    -     �  	O     =   �����A�)kD��,�O��i>jcR            (�/� �= ""�I ��<�_�9����dXY�ʭ��>l��S�2:���˽�c�xl+��؋���>Js�����q	�*��24�Ş4{y�¢K}�0��&}죦95A�{I��I�Bۋf� � p�墜0    �     <  	U     g   �����Unq�Ɨ�h�KY�6����                F   0ArpIpv4Interface::GetTraceResolver (void) const
    �     �  	a     j   ����/�+��l�b4r}9WG��?���            (�/� �� �#�'g���=����dŷOp@����Z��C٠e=q��ɲ�]��}��]c�/tr�&^6�^�� �H��e-�̾рr�̿=T�~�(B�xx�P��F�.�ن$��� ��M��C^�.�/    |     b  	�     �      �O}��.+��$�[�Oe�:            (�/� t� ����
l�(�bٽ����#�a��HS5�ce8� �G/����6�2I�Ę��Y-�����TZ�\���� S	����m�    �    m       �   �����<��q����2ɋ413�            (�/�`� ��e>@K �d��Oc.>�1��JSd��{%���/}1 �&��/2������՟��]ZK�d�V T S }e[M�(	�]"հ����ߙ���;���ij`E�.f�A���Ɵ��)�bU��
ۗj����"o6��&�����<��C��d��M�A�?�@�,ˊ̉�Un��q亲�$�ȓH$���0���J=o�*�F��s����є/V�+hQ5��O���� |CZ=�
�Ҫ��fBm��������}�ؾ a$=+Y��A+C�^��r:��,�r�\�q8�7�,
�)�_�{r�!l�p��&�	� ~���V�ۜ�M��a׬�������d<�(��뢔@-B�w%�n�Y[�1�L�02F2a�̎ð��x���Q��:��A?��Jo�M��S�`����	0�����D�c2�	�� �L�P�����r�b���~j�؀r�������*�2y22tv����oǣC����<��^�Wm?��	j�:GmY�Q��.�az� ��lOa�1�����L��42I��`L4��g�>�F[���@Y^*I��}0������Rf�=� ������B�3��_%    K     �       �   �����(�"��cp[qF{��	            (�/�` � "�&'pi����1���dS^��������̓�B_o��zg,$	�Opݰ�I�l��پ,�?.�e�����s����d���P5��w�����q/�����%}(ʟ���1�
��0�e���XKyc>n�)!2�ʐ�ct D$I ;�B���\��0ż#?�q����h1H�kc�        J  �     �   �������pC@N�lb$�����8            (�/�`
 &�<*P�( � @B�����Y�2@8�UaTF��f!
E��(�)6 / / ��ڱZh��L�D�{�v����@���5u�B ��L�EU�� 8N��8��8�S�=w�YƼ�b�T��B�4=����pVmߺp9�9&�3"�;yQ-C�H�D����(�.���")g}��f�+֗��7Kkd������R��'O�r�ǅ�"�e�y�0�Zh�zf�r��m�M���-���iz"Š ���+j#XM�c_��O3�C]��zy��T&X �d���UB���"��^�ф�CP��u�,�    \    F  �     �   ����1�C�s��3m9�I~�T��            (�/�`X	�! ��6@iE <0�� ��{���)��t޶O�&$4fC��!����UUQ�`�<��G� � � ���ϚR�//\��Ӑ�������mȾ�߹��� l5e �	�2yl�l>���p��2��[�A�1}򗧧2��
��V����Rj��}����Ҋz�X]��P�Z���
�.�H	 	A�F#�l��C�Y��=]^����=_i�h�<��-����2�8d�mE�0��^�=�Q\"�P����! �ap 3��I�K$J3Ul�VX,����pSɍ�)B�H��ս,��A��*�[`t�oB��-s�o���^�e��RХO~6ӣ�%�D�ҥC�1:���љ\X�{r���ڽj7������{�\�/t��7S��Q�.���`�h^���[�P҅�ޫ1 ��O�j�9t=wbYG���c{��Gf���B�҅��h4*�
R�!I�d���5���y[�>�(j���+�t��1�dh�%��gg�fܶ�V�?:�\3ᝆe�L����D*ҵWDr��	��p�VB�����<&�`N}
@�|�;��Ié��X��p"08	x#|=��Ψ�!C���  �$(   !�3 �D�)"I�"KB ���u�	�J��Z(��<��GH ج�!�+�@d�m!e��0�G�U�����Ҫ8XM?]����6A�l������٫ ����2�:� &s��f�;	��K�����p��nTWp>).��Fw�O�9�f~���;�9��2��X �)1�c�,��R)r�+=?�Oa�&�5%� 筚���+t;���x�n�!��6Kv���v{�7Y�Q����� _�;��f+e�z:MR�&\�\Hg�ܵ�7�FB��x�6L���T�D���t47G�{\{�u(h��A��U�	i]��e�X�>���WVn�o9�d�h!�Q�9��;A$s�\�t��.�˫dҳ&?�������
�{,G]f5� ����X���nr97��OM%(����z��@'�N�WEXi�6�z�:>{G� �Ա����=�`��R ]߅O    �     b  �     �   ������'����2.1�o��aq              J  M      �     J          hardwareDestination = GetDevice ()->MakeMulticastAddress(dest);
         f  �     �      C'�mW�D���������            (�/� t� �  �  	   h 
 if (dest.IsBroadcast () ||SubnetDirectedGetNetworkMask ()) )
 S	����m�    j     �  �     �      i���d6�b�����h	,д            (�/�`= � �J##p)p HU��H�����%ߨU*-}�������:�i�i�e�"4��' Ӧ�Q�b_4�Ƃ)��2��� �wP�B�vˌ&ʪlG��$�j�A���WOQ>m0��i�s��o�ǘ�#�޹ �=��8��b�_�  y�o�)�Q��"���C w���!Y�@���9    (    �  �      �   �����L\k�u�C0^���oc            (�/�`l] �*�> O � �0��Q�åNW(���"��F�~!�p�H�)���PNS3�i���W��VM\#�3z~ u } ���mH�na�g�}���=e��6�m�V�:�A��bа��:�Un��H5�zf�pd0!Ж�:�s	i:��6��Mo�I�+ct5(���A.��+`{�.T,�т�PR�Hy�C@�,.L�ͣq!l0lի\�qu?�*$v
�)T]IU�Qˮc�QH� ��U]S���'���-��r�l�N�c^�����6QC9�[��u56etK��g���.�KDl�K�^�' �D��t	��#�3Cݭ�&n��~����n*�С���I��J����ќ��j'�.fi�!��µ�}Vm�K��]������{�et�T�<کꗍ�Ӂ���Ğ�aU���-�@���Y5�x
&��Ʃ��qW�*��N��S ;��>1�GL<�	[��pvJvU^����bbkL�i��
X=I�9;�y�u�KNI����늼�����OP�����Ū�]�'�����h=�K�����d�����a�S�рAP @F)3 �,��S����h
'�U��_72t<�#G�ٙ|�!�2���?�&M4����z��S����A.`���H8&�.#'�KT	 ���څ�+8f�Vo���5&�oZ4��$����5.��~(�,��0#yۙq���N�~�EܖF�C���?���n)� Z�[��jQ<�=�g[K���g#~8��C=	Q�v#-52�d0���`h=���'����'���O�fX0}9�Y��b\� #	��,�~�qP���Ė�S�q��a��������=%ì��/��+�ӘW��D�I4�7{G�)�    �     2  �      $    ����*�2����0$4�T��R�L,                @   &  NS_LOG_PARAMS (this << &p << dest);
    �     �  �   !  J    �����C�&0X�4.�? ��q;.٬              �  �   ;ArpIpv4Interface::SendTo (Ptr<Packet> p, Ipv4Address dest)
    3   2  NS_LOG_PARAM ("(" << p << ", " << dest << ")");
    t     1  �   "  N   !   "�F�����k�=��(����                D   %  NS_LOG_PARAMS (this << p << dest);
    �     >  �   #  �   #����/C:1��y�R�PaF-g�              �     2        m_node->QueryInterface<ArpL3Protocol> ();
    �     9  �   $  �   $�����T���أ�T:���e              �  �   -        m_node->GetObject<ArpL3Protocol> ();
              %  	�   %����MP��1c�3D����x��'e              }  �      \  �        4     �  �   &  
    &����g��^$��
,K����zЩl            (�/�`u � R�#�� 0�0�o,$R"�*�d�q������.��Xݠ����Жt>Ȟ�7�a�� �)h3��ݔ��w���Y�zO�[p��oV槠 �̠����M�C�щ��ɲ��n r��7� ���MT��`�5 c� @aʐXp���M0�M 6X���[-zB 3�S����[�t    �       �   '     '���� r�v7�)
4~����vC!���               c   {        �     b  �   (  �   (�������Yp�Z]P�Gx�Z^�誡            (�/� �� �  u  �     NS_LOG_FUNCTION_NOARGS ();
  �  �D  |   ' (this << pdest);
 (�3
�TP     a      �   )  K   )����9��B�djFEc�$mH            (�/�`�e �YW8@k� �|��g� y��O0eɔ�~&�6���CP�ft���:ٍ(�$*�MF?J F G ��P���b���V�A0���<�$~�R�%EbC)�Z��
��{Z�%`�9D�qR�t�0�<$X v�1���E#I���0~�b��� �9�8�J�Ć�c���y�iu������;ˈ�ۂ�z^M���*��� 'Uf�ٳV"(��IC�S��K�qn6�G�9͚-��/�r���o`�m/nZ4pJ��ҿ`���&��f��oSm���dl�%\�X���(�$͓G�1|D1sR@����Fh�Z�0���z(�]��(z���F�~,!B�zPF�)L��
@@s % Ui�(M��
��	���}x`��U�I1�}��dE�z����=a�n����HB���C�kҹ��	����#"��%�~��Z�|n��>���|�368�
�F0
-�Uc`�,S��	�g�/��O�LIƷ��QiLS����I闞�%    "w     i      *  M   *�����p��1S��0w�:��}�%M            (�/� � $  c  �     NS_LOG_FUNCTION (this);
  �  ��$   Ipv4Interface::DoDispose ();
 ���v�FU